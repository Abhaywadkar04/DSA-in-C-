class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        int n = s.length();
        
      
        int i;
        for (i = n; i > 0; --i) {
            if (isPalindrome(s.substr(0, i))) {
                break; 
            }
        }
        
       
        if (i == n) return s;
        
        
        string unmatch = s.substr(i); 
        reverse(unmatch.begin(), unmatch.end());
        
        return unmatch + s; 
    }
    
    bool isPalindrome(const string& str) {
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};