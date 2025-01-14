class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>map;
        vector<int>answer(A.size());

        for(int i=0;i<A.size();i++){
            map[A[i]]++;
            map[B[i]]++;
            int common=0;

            for(auto [key,freq]:map){
                if(freq>=2)common++;
            }
            answer[i]=common;



            

        }
        return answer;
    }
};