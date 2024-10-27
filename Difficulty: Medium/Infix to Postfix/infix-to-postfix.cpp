//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string ans = "";
        stack<char> op;

        for (int i = 0; i < s.length(); i++) {
            // If character is an operand, add it to the output
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
            } 
            // If character is '(', push it to the stack
            else if (s[i] == '(') {
                op.push(s[i]);
            } 
            // If character is ')', pop and output from the stack until '(' is found
            else if (s[i] == ')') {
                while (!op.empty() && op.top() != '(') {
                    ans += op.top();
                    op.pop();
                }
                op.pop(); // Pop '('
            } 
            // If an operator is encountered
            else {
                while (!op.empty() && (
                    ((s[i] == '+' || s[i] == '-') && (op.top() == '+' || op.top() == '-' || op.top() == '*' || op.top() == '/' || op.top() == '^')) ||
                    ((s[i] == '*' || s[i] == '/') && (op.top() == '*' || op.top() == '/' || op.top() == '^')) ||
                    (s[i] == '^' && op.top() == '^'))) {
                    ans += op.top();
                    op.pop();
                }
                op.push(s[i]); // Push current operator
            }
        }

        // Pop all remaining operators from the stack
        while (!op.empty()) {
            ans += op.top();
            op.pop();
        }

        return ans;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends