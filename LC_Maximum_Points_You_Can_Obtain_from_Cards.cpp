#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        // Time Complexity :- O(K)
        // Space Complexity :- O(1)
        
        int n = cardPoints.size() ;

        int leftSum = 0 ; 
        int rightSum = 0 ;
        int maxSum = INT_MIN ;

        for( int i = 0 ;  i <= k-1 ; i++ ){
            leftSum = leftSum += cardPoints[i] ;
        }

        maxSum = leftSum ;
        int rightIndex = n-1 ;

        for( int i = k-1 ; i >= 0 ; i-- ){

            leftSum = leftSum - cardPoints[i] ;
            rightSum = rightSum + cardPoints[rightIndex] ;
            rightIndex = rightIndex - 1 ;
            maxSum = max( maxSum , leftSum + rightSum ) ;

        }

        return maxSum ;

    }
};