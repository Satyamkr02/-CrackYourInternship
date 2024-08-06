#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        stack<int> stk;

        Node *cur = head;

        while (cur != NULL)
        {

            if (cur->data == 2)
            {
                stk.push(cur->data);
            }

            cur = cur->next;
        }

        cur = head;

        while (cur != NULL)
        {

            if (cur->data == 1)
            {
                stk.push(cur->data);
            }

            cur = cur->next;
        }

        cur = head;

        while (cur != NULL)
        {

            if (cur->data == 0)
            {
                stk.push(cur->data);
            }

            cur = cur->next;
        }

        cur = head;

        while (cur != NULL)
        {

            cur->data = stk.top();
            stk.pop();

            cur = cur->next;
        }

        return head;
    }
};
