#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        int n = s.length() ;

        string word = "" ;
        stack<string> stk ;

        string ans ;

        for( int i = 0 ; i < n ; i++ ){

            if( s[i] != ' ' ) word.push_back( s[i] ) ;

            if( s[i+1] == ' ' || i+1 == n ){
                if( word.length() != 0 )
                    stk.push( word ) ;

                word = "" ;
            }

        }

        while( !stk.empty() ){

            ans.append( stk.top() ) ;
            stk.pop() ;

            if( !stk.empty() ){
                ans.push_back( ' ' ) ;
            }

        }

        return ans ;
        
    }
};


int main()
{
    return 0;
}