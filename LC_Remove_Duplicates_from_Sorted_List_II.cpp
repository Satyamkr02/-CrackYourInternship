#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        unordered_map<int, int> eleFreq;

        ListNode* cur = head;
        while (cur != nullptr) {
            eleFreq[cur->val]++;
            cur = cur->next;
        }

        set<int> unqEle;

        for (auto val : eleFreq) {
            if (val.second == 1)
                unqEle.insert(val.first);
        }

        ListNode* result_Head = nullptr;
        ListNode* result_Tail = nullptr;

        for (auto ele : unqEle) {

            ListNode* newNode = new ListNode(ele);

            if (result_Head == nullptr) {
                result_Head = newNode;
                result_Tail = newNode;
            } else {
                result_Tail->next = newNode;
                result_Tail = newNode;
            }

            ele++;
        }

        return result_Head;
    }
};