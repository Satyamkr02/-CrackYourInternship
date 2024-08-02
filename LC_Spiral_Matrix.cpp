#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans ;

        int row = matrix.size() ;
        int col = matrix[0].size() ;

        int startingRow = 0 ;
        int endingRow = row - 1 ;
        int startingCol = 0 ;
        int endingCol = col - 1 ;

        int count = 0 ;
        int total = row * col ;

        while( count < total ){

            // Firstly We
            // Moving from Left to Right
            for( int index = startingCol ; count < total && index <= endingCol ; index++ ){
                ans.push_back( matrix[ startingRow ][ index ] ) ;
                count++ ;
            }

            startingRow++ ;

            // Moving from Top to Bottom
            for( int index = startingRow ; count < total && index <= endingRow ; index++ ){
                ans.push_back( matrix[ index ][ endingCol ] ) ;
                count++ ;
            }

            endingCol-- ;

            // Moving from Right to Left
            for( int index = endingCol ; count < total && index >= startingCol ; index-- ){
                ans.push_back( matrix[ endingRow ][ index ] ) ;
                count++ ;
            }

            endingRow-- ;

            // Moving from Bottom to Top
            for( int index = endingRow ; count < total && index >= startingRow ; index-- ){
                ans.push_back( matrix[ index ][ startingCol ] ) ;
                count++ ;
            }

            startingCol++ ;

        }
        
        return ans ;

    }
};

int main()
{
    return 0;
}