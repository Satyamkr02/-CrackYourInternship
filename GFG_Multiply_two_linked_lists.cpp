#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution {
  public:
  
    const long long mod = 1e9 + 7 ;
  
    long long moduloMul( long long a , long long b ){
        
        return ( ( a % mod ) * ( b % mod ) ) % mod ;
        
    }
    
    long long power( int x , int y ){
        
        if( y == 0 )
            return 1 ;
        
        long long partialAns = power( x , y/2 ) ;
        
        partialAns = moduloMul( partialAns , partialAns ) ;
        
        if( y % 2 == 0 ){
            return partialAns ;
        }else{
            return x * partialAns ;
        }
        
    }
    
    
    long long LLtoNum( Node* head ){
        
        Node* cur = head ;
        long long len = 0 ;
        
        while( cur != NULL ){
            len++ ;
            cur = cur -> next ;
        }
        
        long long pow = len - 1 ;
        
        long long ans = 0 ;
        
        cur = head ;
        while( cur != NULL ){
            
            ans = ans + moduloMul( cur -> data , power( 10 , pow ) ) ;
            pow-- ;
            
            cur = cur -> next ;
        }
        
        return ans ;
        
    }
    
  
  
    long long multiplyTwoLists(Node *first, Node *second) {
        
        long long num1 = LLtoNum( first ) ;
        long long num2 = LLtoNum( second ) ;
        
        return moduloMul( num1 , num2 ) ;
        
    }
};