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
    ListNode* partition(ListNode* head, int x) {

        if( head == nullptr || head -> next == nullptr )
            return head ;
        
        vector<int> arr ;
        int n = 0 ;

        ListNode* cur = head ;

        while( cur != nullptr ){
            n++ ;
            arr.push_back( cur -> val ) ;
            cur = cur -> next ;
        }

        deque<int> lessThanX ;
        deque<int> moreThanX ;

        for( int i = 0 ; i < n ; i++ ){

            if( arr[i] < x ){
                lessThanX.push_back( arr[i] ) ;
            }else{
                moreThanX.push_back( arr[i] ) ;
            }

        }

        cur = head ;

        while( !lessThanX.empty() ){

            cur -> val = lessThanX.front() ;
            lessThanX.pop_front() ;
            cur = cur -> next ;

        }

        while( !moreThanX.empty() ){

            cur -> val = moreThanX.front() ;
            moreThanX.pop_front() ;
            cur = cur -> next ;

        }
        
        return head ;

    }
};