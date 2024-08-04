#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int applyOp(int a, int b, char op) {
        switch(op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }

    int calculate(string s) {
        stack<int> values;   // Stack to store integers
        stack<char> ops;     // Stack to store operators
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ')
                continue;

            // If the current character is a digit, push it to the values stack
            if (isdigit(s[i])) {
                int val = 0;
                // Handle multi-digit numbers
                while (i < n && isdigit(s[i])) {
                    val = (val * 10) + (s[i] - '0');
                    i++;
                }
                values.push(val);
                i--; // Since i++ happens in the loop, counteract it here
            }
            // If the current character is an operator
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                // Apply the operator on the top two elements if precedence allows
                while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                    int val2 = values.top();
                    values.pop();
                    
                    int val1 = values.top();
                    values.pop();
                    
                    char op = ops.top();
                    ops.pop();
                    
                    values.push(applyOp(val1, val2, op));
                }
                ops.push(s[i]);
            }
        }

        // Entire string has been parsed, apply remaining ops to remaining values
        while (!ops.empty()) {
            int val2 = values.top();
            values.pop();
            
            int val1 = values.top();
            values.pop();
            
            char op = ops.top();
            ops.pop();
            
            values.push(applyOp(val1, val2, op));
        }

        // Top of 'values' contains result
        return values.top();
    }

    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }
};
