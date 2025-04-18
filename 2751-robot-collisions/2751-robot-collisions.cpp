#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> robots;

        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        stack<tuple<int, int, int>> stk; 

        vector<int> finalHealth(n, 0); // initially 0, updated for survivors

        for (auto &[pos, health, dir, idx] : robots) {
            if (dir == 'R') {
                stk.push({pos, health, idx});
            } else {
                while (!stk.empty()) {
                    auto [rpos, rhealth, ridx] = stk.top();

                    if (rhealth < health) {
                        stk.pop();
                        health--; 
                    } else if (rhealth == health) {
                        stk.pop();
                        health = 0;
                        break;
                    } else {
                        get<1>(stk.top())--; 
                        health = 0;
                        break;
                    }
                }
                if (health > 0) {
                    finalHealth[idx] = health;
                }
            }
        }

        while (!stk.empty()) {
            auto [rpos, rhealth, ridx] = stk.top();
            stk.pop();
            finalHealth[ridx] = rhealth;
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (finalHealth[i] > 0) {
                result.push_back(finalHealth[i]);
            }
        }

        return result;
    }
};
