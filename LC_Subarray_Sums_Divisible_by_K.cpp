#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map< int , int > remainderCount ;
        remainderCount[0] = 1 ;

        int ans = 0 ;
        int sum = 0 ;

        for( auto ele : nums ){

            sum += ele ;
            int remainder = sum % k ;

            if( remainder < 0 ) remainder = remainder + k ;

            if( remainderCount.find( remainder ) != remainderCount.end() ){
                ans += remainderCount[remainder] ;
            }

            remainderCount[remainder]++ ;

        }

        return ans ;

    }
};

int main()
{
    return 0;
}