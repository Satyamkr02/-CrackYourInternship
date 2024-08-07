#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

// #include<bits/stdc++.h>
#include<queue>

class Solution {
  public:
    Node* divide(Node* head) {
        
        queue<int> odd ;
        queue<int> even ;
        
        Node* cur = head ;
        
        while( cur != NULL ){
            
            if( cur -> data % 2 == 0 ){
                even.push( cur -> data ) ;
            }else{
                odd.push( cur -> data ) ;
            }
            
            cur = cur -> next ;
            
        }
        
        cur = head ;
        
        while( !even.empty() ){
                
            cur -> data = even.front() ;
            even.pop() ;
            cur = cur -> next ;
                
        }
            
        while( !odd.empty() ){
                
            cur -> data = odd.front() ;
            odd.pop() ;
            cur = cur -> next ;
                
        }
        
        return head ;
        
    }
};