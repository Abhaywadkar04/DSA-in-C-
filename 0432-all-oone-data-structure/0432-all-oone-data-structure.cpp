#include <unordered_map>
#include <string>
#include <climits>  // For INT_MAX and INT_MIN

class AllOne {
public:
    // Declare the unordered_map to store key -> count
    std::unordered_map<std::string, int> map;

    // Constructor
    AllOne() {}

    // Increment the count of the given key
    void inc(std::string key) {
        map[key] += 1;
    }

    // Decrement the count of the given key
    void dec(std::string key) {
        if (--map[key] == 0) {
            map.erase(key);  // Remove the key if the count becomes 0
        }
    }

    // Return the key with the maximum count
    std::string getMaxKey() {
        if (map.empty()) return "";  // Return empty string if the map is empty

        std::string maxKey;
        int maxCount = INT_MIN;

        // Iterate through the map to find the key with the maximum count
        for (const auto& [key, count] : map) {
            if (count > maxCount) {
                maxCount = count;
                maxKey = key;
            }
        }
        return maxKey;
    }

    // Return the key with the minimum count
    std::string getMinKey() {
        if (map.empty()) return "";  // Return empty string if the map is empty

        std::string minKey;
        int minCount = INT_MAX;

        // Iterate through the map to find the key with the minimum count
        for (const auto& [key, count] : map) {
            if (count < minCount) {
                minCount = count;
                minKey = key;
            }
        }
        return minKey;
    }
};
