#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int len1 = 0 ;
        int len2 = 0 ;

        ListNode* curA = headA ;
        ListNode* curB = headB ;

        while( curA != NULL ){
            len1++ ;
            curA = curA -> next ;
        }

        while( curB != NULL ){
            len2++ ;
            curB = curB -> next ;
        }

        int diff = abs( len1 - len2 ) ;

        curA = headA ;
        curB = headB ;

        if( len1 < len2 ){
            while( diff-- ){
                curB = curB -> next ;
            }
        }else{
            while( diff-- ){
                curA = curA -> next ;
            }
        }

        while( curA != NULL && curB != NULL ){
            
            if( curA == curB ){
                return curA ;
            }

            curA = curA -> next ;
            curB = curB -> next ;            

        }

        return NULL ;


        
    }
};