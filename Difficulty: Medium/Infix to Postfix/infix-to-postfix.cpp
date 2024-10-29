//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int priority(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }
       
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
          
        string ans="";
        stack<char>stk;
        
        int i=0;
        while(i<s.length()){
            
            if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
                ans +=s[i];
            }
            else if(s[i]=='('){
                stk.push(s[i]);
            }
            else if(s[i]==')'){
                while(!stk.empty() && stk.top()!='('){
                    ans +=stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            
            else{
                while(!stk.empty() && priority(s[i])<=priority(stk.top())){
                    ans +=stk.top();
                    stk.pop();
                    
                }
                stk.push(s[i]);
            }
            i++;
        }
        
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        
        return ans;
        // Your code here
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