#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if( head == nullptr )
            return head ;

        int len = 0 ;
        ListNode* cur = head ;

        while( cur != nullptr ){
            len++ ;
            cur = cur -> next ;
        }

        if( len == n ){

            ListNode* del = head ;
            head = head -> next ;
            delete del ;
            return head ;
        }

        cur = head ;
        int destiny = len - n ;
        int position = 0 ;

        while( cur != nullptr ){
            position++ ;
            if( position == destiny ){
                ListNode* del = cur -> next ;
                cur -> next = cur -> next -> next ;
                delete del ;
                break ; 
            }
            cur = cur -> next ;
        }

        return head ;
        
    }
};