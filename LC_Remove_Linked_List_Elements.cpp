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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy = new ListNode(0) ;
        dummy -> next = head ;

        ListNode* prev = dummy ;
        ListNode* cur = head ;

        while( cur != nullptr ){

            if( cur -> val == val ){
                prev -> next = cur -> next ;            
            }else{
                prev = cur;  
            }

            cur = cur -> next ;
            
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node
        return newHead;
        
    }
};

int main()
{
    return 0;
}