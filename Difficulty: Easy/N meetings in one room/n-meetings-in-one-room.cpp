//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        
        int n = start.size();
        vector<pair<int, int>> meetings;

        // Storing start and end times in a pair and pushing them into a vector
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        // Sorting the meetings by their end times
        sort(meetings.begin(), meetings.end());

        // Initialize count of meetings
        int count = 1;
        int last_end = meetings[0].first;

        for (int i = 1; i < n; i++) {
            // If the start time of the current meeting is after the end time of the last meeting
            if (meetings[i].second > last_end) {
                count++;
                last_end = meetings[i].first;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends