#include<iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std ;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size() ;

        sort( nums.begin() , nums.end() ) ;

        int ans = -1 ;

        for( int i = 0 ; i < n-1 ; i++ ){

            if( nums[i] == nums[i+1] ){
                ans = nums[i] ;
                break ;
            }  

        }

        return ans ;
        
    }
};