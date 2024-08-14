class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();

        // Edge case: If needle is empty, return 0
        if (needleLen == 0) return 0;

        // Edge case: If needle is longer than haystack, return -1
        if (needleLen > haystackLen) return -1;

        // Iterate through possible starting points in haystack
        for (int i = 0; i <= haystackLen - needleLen; i++) {
            int j = 0;
            // Check if the substring starting at index i matches needle
            while (j < needleLen && haystack[i + j] == needle[j]) {
                j++;
            }
            // If the entire needle was matched, return the start index
            if (j == needleLen) {
                return i;
            }
        }

        // If needle was not found, return -1
        return -1;
    }
};
