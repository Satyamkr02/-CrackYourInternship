#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        int n = s.length() ;
        stack<char> stk ;

        if( s[0] == ')' || s[0] == ']' || s[0] == '}' ){
            return false ;
        }

        for( int i = 0 ; i < n ; i++ ){

            if( s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                stk.push( s[i] ) ;
            }
            else{

                if( stk.empty() ) return false ;
                else if( s[i] == ')' and stk.top() == '(' ||
                s[i] == ']' and stk.top() == '[' ||
                s[i] == '}' and stk.top() == '{' )
                {
                    stk.pop() ;
                }
                else{
                    return false ;
                }

            }
            

        }

        if( stk.empty() ){
            return true ;
        }


        return false ;
        
    }
};


int main()
{
    return 0;
}