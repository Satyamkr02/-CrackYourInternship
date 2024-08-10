#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size() ;
        set<int> uniqueVal ;

        for( int i = 0 ; i < n ; i++ ){

            uniqueVal.insert( nums[i] ) ;

        }

        int i = 0 ;
        for( auto val : uniqueVal ){

            nums[i++] = val ;
            val++ ;

        }
        
        return uniqueVal.size() ;
        
    }
};