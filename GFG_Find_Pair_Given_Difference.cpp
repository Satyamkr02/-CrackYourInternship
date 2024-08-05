#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_map<int, int> freq;
        
        // Count the frequency of each element
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        // Check for pairs
        for (int i = 0; i < n; i++) {
            int findEle1 = arr[i] + x;
            int findEle2 = arr[i] - x;
            
            // Check if findEle1 exists and is different from arr[i] or has more than one occurrence
            if ((freq.find(findEle1) != freq.end() && (findEle1 != arr[i] || freq[findEle1] > 1)) ||
                (freq.find(findEle2) != freq.end() && (findEle2 != arr[i] || freq[findEle2] > 1))) {
                return 1; // Pair found
            }
        }
        
        return -1;
    }
};