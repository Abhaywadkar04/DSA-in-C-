

class Solution {
public:
    bool canConstruct(const std::string& ransomNote, const std::string& magazine) {
        unordered_map<int, int> rmap;
        unordered_map<int, int> mmap;

        for(char c : ransomNote) {
            rmap[c]++;
        }
        
        for(char c : magazine) {
            mmap[c]++;
        }

        
        for(const auto& pair : rmap) {
            char c = pair.first;
            int count = pair.second;
            if(mmap[c] < count) {
                return false;
            }
        }

        return true;
    }
};
