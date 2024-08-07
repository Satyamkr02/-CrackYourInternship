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
    void reorderList(ListNode* head) {

        if( head == nullptr || head -> next == nullptr ) return ;

        ListNode* cur = head ;
        int n = 0 ;
        vector<int> arr ;

        while( cur != nullptr ){
            n++ ;
            arr.push_back( cur -> val ) ;
            cur = cur -> next ;
        }

        int TotalEle = n ;

        vector<int> first ;
        vector<int> second ;

        int left = 0 ;
        int right = n-1 ;
        
        while( left <= right ){

            if( TotalEle > 0 ){
                first.push_back( arr[left++] ) ;
                TotalEle-- ;
            }
            if( TotalEle > 0 ){
                second.push_back( arr[right--] ) ;
                TotalEle-- ;
            }

        }

        int i = 0 ;
        int j = 0 ;
        int count = 0 ;

        cur = head ;
        while( cur != nullptr ){
            if( count <= n && cur != nullptr ){
                cur -> val = first[i++] ;
                count++ ;
                cur = cur -> next ;
            }
            
            if( count <= n && cur != nullptr ){
                cur -> val = second[j++] ;
                count++ ;
                cur = cur -> next ;
            }
            

        }
        
    }
};