#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size() ;

        vector<int> ans( 2 , -1 ) ;

        unordered_map< int , int > valToIdx ;

        for( int i = 0 ; i < n ; i++ ){
            valToIdx.insert( { nums[i] , i } ) ;
        }

        for( int i = 0 ; i < n ; i++ ){

            int findEle = target - nums[i] ;
            if( valToIdx.find(findEle) != valToIdx.end() ){
                ans[0] = i ;
                if( i != valToIdx[findEle] ){
                    ans[1] = valToIdx[findEle] ;
                    break ;
                }

            }

        }

        return ans ;
        
    }
};

int main()
{
    return 0;
}