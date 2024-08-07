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

    int pow( int a , int b ){

        if( b == 0 ){
            return 1 ;
        }

        int partialAns = pow( a , b/2 ) ;

        if( b % 2 == 0 ){
            return partialAns * partialAns ;
        }else{
            return a * partialAns * partialAns ;
        }

    }

    int getDecimalValue(ListNode* head) {

        ListNode* cur = head ;
        int len = 0 ; 

        while( cur != nullptr ){
            len++ ;
            cur = cur -> next ; 
        }

        cur = head ;
        len = len - 1 ;

        int ans = 0 ;
        while( cur != nullptr ){
            ans = ans + ( cur -> val ) * ( pow( 2 , len-- ) ) ;
            cur = cur  -> next ;
        }

        return ans ;        
        
    }
};