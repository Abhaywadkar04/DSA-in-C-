class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer;

        for (int i = 0; i < prices.size(); i++) {
            bool discount = false;
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    answer.push_back(prices[i] - prices[j]);
                    discount = true;
                    break;
                }
            }
            if (!discount) {
                answer.push_back(prices[i]); 
            }
        }
        return answer; 
    }
};
