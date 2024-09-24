class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<string,int>map;


        for(int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            string prefix="";

            for(int i=0;i<s.length();i++){
                prefix +=s[i];

                map[prefix]++;
            }
        }

        int maxlength =0;

        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            string prefix="";

            for(int i=0;i<s.length();i++){
                prefix +=s[i];
                if(map.find(prefix) != map.end()){
                    maxlength=max(maxlength,static_cast<int>(prefix.length()));
                }
            }


        }


        return maxlength;
    }
};