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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size() ;
        vector<int> ans ;

        for( int i = 0 ; i < n ; i++ ){

            ListNode* cur = lists[i] ;

            while( cur != nullptr ){
                ans.push_back( cur -> val ) ;
                cur = cur -> next ;
            }

        }

        sort( ans.begin() , ans.end() ) ;

        ListNode* result_Head = nullptr ;
        ListNode* result_Tail = nullptr ;

        for( int i = 0 ; i < ans.size() ; i++ ){

            ListNode* newNode = new ListNode( ans[i] ) ;

            if( result_Head == nullptr ){
                result_Head = newNode ;
                result_Tail = newNode ;
            }else{
                result_Tail -> next = newNode ;
                result_Tail = newNode ;
            }

        }

        return result_Head ;
        
    }
};