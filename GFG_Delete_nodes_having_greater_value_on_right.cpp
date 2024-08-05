#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node *compute(Node *head)
    {
        // Reverse the linked list
        Node* prev = nullptr;
        Node* cur = head;
        Node* next = nullptr;

        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // Now `prev` is the new head of the reversed list
        Node* newHead = prev;
        Node* maxNode = newHead;
        cur = newHead->next;

        while (cur != nullptr) {
            if (cur->data < maxNode->data) {
                // Skip nodes that are less than the maxNode
                maxNode->next = cur->next;
                delete cur;  // delete the node to free memory
            } else {
                // Update maxNode
                maxNode = cur;
            }
            cur = maxNode->next;
        }

        // Reverse the list again to restore original order
        prev = nullptr;
        cur = newHead;

        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // Now `prev` is the new head of the final linked list
        return prev;
    }
};
