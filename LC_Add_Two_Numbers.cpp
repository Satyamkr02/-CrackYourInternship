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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* Result_Head = nullptr ;
        ListNode* Result_Tail = nullptr ;

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = 0 ;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry ;

            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);

            if( Result_Head == nullptr ){
                Result_Head = newNode ;
                Result_Tail = newNode ;
            }else{
                Result_Tail -> next = newNode ;
                Result_Tail = newNode ;
            }

        }

        return Result_Head;
    }
};
