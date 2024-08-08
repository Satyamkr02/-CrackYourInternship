#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        
        vector< int > values ;
        
        Node* cur = root ;
        
        while( cur != NULL ){
            
            Node* curBottom = cur ;
            while( curBottom != NULL ){
                
                values.push_back( curBottom -> data ) ;
                curBottom = curBottom -> bottom ;
                
            }
            
            cur = cur -> next ;
            
        }
        
        sort( values.begin() , values.end() ) ;
        
        if ( values.empty() ) return NULL;
        
        
        Node* newhead = new Node( values[0] ) ;
        cur = newhead ;
        
        for( int i = 1 ; i < values.size() ; i++ ){
            
            Node* newNode = new Node( values[i] ) ;
            cur -> bottom = newNode ;
            cur = newNode ;
            
        }
        
        return newhead ;
        
    }
};