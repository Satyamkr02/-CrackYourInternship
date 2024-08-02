#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        int n = nums.size() ;

        vector<int> ans ;

        unordered_map< int , int > EleFreq ;

        for( int i = 0 ; i < n ; i++ ){

            EleFreq[nums[i]]++ ;

        }

        for( auto ele : EleFreq ){

            if( ele.second > 1 ){
                ans.push_back( ele.first ) ;
            }

        }

        return ans ;
        
    }
};


int main()
{
    return 0;
}