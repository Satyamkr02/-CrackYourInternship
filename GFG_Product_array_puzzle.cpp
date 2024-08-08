#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        
        int n = nums.size() ;

        vector< long long int > ans(n) ;
        unordered_map< long long int , long long int > eleFreq ;
        
        long long int TotalMul = 1 ;
        long long int flag = 0 ;
        
        
        for( int i = 0 ; i < n ; i++ ){
            
            eleFreq[nums[i]]++ ;
            
            if( nums[i] != 0 ){
                TotalMul = TotalMul * nums[i] ;
            }
            else{
                flag = 1 ;
            }
                
        }
        
        if( flag ){
            
            for( int i = 0 ; i < n ; i++ ){
            
                if( nums[i] != 0 ){
                    ans[i] = 0 ;
                }
                else if( eleFreq[0] > 1 ){
                    ans[i] = 0 ;
                }
                else{
                    ans[i] = TotalMul ;
                }
            
            }
            
        }
        else{
            
            for( int i = 0 ; i < n ; i++ ){
            
                ans[i] = TotalMul / nums[i] ;
            
            }
            
        }
        
        
        
        return ans ;
        
    }
};