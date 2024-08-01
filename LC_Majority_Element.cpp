#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map< int , int > EleFreq ;

        for( auto ele : nums ){

            EleFreq[ele]++ ;

        }

        int maxFreq = 0 ;
        int majorityElement = nums[0] ;

        for( auto& pair : EleFreq ){

            if( pair.second > maxFreq ){
                maxFreq = pair.second ;
                majorityElement = pair.first ;
            }

        }

        return majorityElement ;

    }
};

int main()
{
    return 0;
}