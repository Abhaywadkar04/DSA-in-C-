class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                stk.push_back(asteroids[i]);
            } else {
                while (!stk.empty() && stk.back() > 0 && stk.back() < abs(asteroids[i])) {
                    stk.pop_back();
                }
                if (!stk.empty() && stk.back() == abs(asteroids[i])) {
                    stk.pop_back();
                } else if (stk.empty() || stk.back() < 0) {
                    stk.push_back(asteroids[i]);
                }
            }
        }
        return stk;
    }
};
