class Solution {
    void buildHeapSort(vector<pair<int, char>>& pairs) {
        int n = pairs.size();
        // Start from the last internal node and heapify all nodes
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(pairs, n, i);
        }
    }

    void heapify(vector<pair<int, char>>& pairs, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2; // Right child

        // Compare with left child
        if (left < n && pairs[largest].first < pairs[left].first) {
            largest = left;
        }

        // Compare with right child
        if (right < n && pairs[largest].first < pairs[right].first) {
            largest = right;
        }

        // If the largest is not root
        if (largest != i) {
            swap(pairs[i], pairs[largest]);
            // Recursively heapify the affected sub-tree
            heapify(pairs, n, largest);
        }
    }

    pair<int, char> greatestElement(vector<pair<int, char>>& pairs) {
        int n = pairs.size();
        pair<int, char> maxElement = pairs[0]; // Max element is at root (index 0)

        // Move the last element to the root and reduce the heap size
        pairs[0] = pairs[n - 1];
        pairs.pop_back(); // Remove last element from heap

        // Heapify root to maintain heap property
        heapify(pairs, pairs.size(), 0);

        return maxElement;
    }

public:
    string frequencySort(string s) {
        unordered_map<char, int> map;

        // Count frequency of each character
        for (const char& ch : s) {
            map[ch]++;
        }

        // Build a vector of (frequency, character) pairs
        vector<pair<int, char>> pairs;
        for (const auto& ele : map) {
            pairs.push_back({ele.second, ele.first});
        }

        // Build the max-heap
        buildHeapSort(pairs);

        // Rebuild the result string
        string answer;
        while (!pairs.empty()) {
            pair<int, char> element = greatestElement(pairs);
            // Append character `element.second` `element.first` times
            answer.append(element.first, element.second);
        }

        return answer;
    }
};
