#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.length() - 1 ;
        int j = b.length() - 1 ;

        int carry = 0 ;
        string ans = "" ;

        while( i >= 0 || j >= 0 || carry ){

            int sum = carry ;
            if( i >= 0 ) sum += a[i--] - '0' ;
            if( j >= 0 ) sum += b[j--] - '0' ;

            carry = sum > 1 ? 1 : 0 ;

            if( sum % 2 ){
                ans.push_back( '1' ) ;
            }else{
                ans.push_back( '0' ) ;
            }

        }

        reverse( ans.begin() , ans.end() ) ;
        return ans ;
        
    }
};