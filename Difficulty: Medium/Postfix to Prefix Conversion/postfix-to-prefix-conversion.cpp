//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        stack<string> s;

        for (char c : post_exp) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                s.push(string(1, c));
            } else {
                if (s.size() < 2) {
                    // Handle error: not enough operands for the operator
                    return ""; // or throw an exception based on your needs
                }
                string opt2 = s.top();
                s.pop();
                string opt1 = s.top();
                s.pop();
                string x = c + opt1 + opt2;
                s.push(x);
            }
        }

        if (s.size() != 1) {
            return ""; 
        }

        return s.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends