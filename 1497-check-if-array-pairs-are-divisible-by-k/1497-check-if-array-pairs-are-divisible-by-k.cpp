class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>map;

        for(auto i:arr){
            int rem= ((i % k) + k) % k ;
            map[rem]++;
        }
        
       for (auto const& i : map) {
            int rem = i.first;  
            int count = i.second; 

            if (rem == 0) {
                if (count % 2 != 0) {
                    return false;
                }
            }
            else if (map[rem] != map[k - rem]) {
                return false;
            }
        }

        return true;
    }
};