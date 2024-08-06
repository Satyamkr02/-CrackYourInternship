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
    bool isPalindrome(ListNode* head) {

        vector<int> values ;

        ListNode* cur = head ;
        while( cur != nullptr ){

            values.push_back( cur -> val ) ;
            cur = cur -> next ;

        }

        int left = 0 ;
        int right = values.size() - 1 ;

        while( left < right ){

            if( values[left++] != values[right--] ){

                return false ;

            }

        }

        return true ;
        
    }
};