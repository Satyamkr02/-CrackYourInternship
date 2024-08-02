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
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* cur = head;

        // First pass to calculate the length of the list
        while(cur != nullptr) {
            length++;
            cur = cur->next;
        }

        // Find the middle index
        int middle = length / 2 ;

        // Second pass to reach the middle node
        cur = head;
        while(middle--) {
            cur = cur->next;
        }

        return cur;
    }
};


int main() {
    


    return 0;
}
