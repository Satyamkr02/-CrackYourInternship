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
    ListNode* sortList(ListNode* head) {

        if( head == nullptr || head -> next == nullptr )
            return head ;

        vector<int> value ;

        ListNode* cur = head ;

        while( cur != nullptr ){
            value.push_back( cur -> val ) ;
            cur = cur -> next ;
        }

        cur = head ;
        
        sort( value.begin() , value.end() ) ;

        int idx = 0 ;
        while( cur != nullptr ){
            cur -> val = value[idx++] ;
            cur = cur -> next ;
        }

        return head ;

    }
};
