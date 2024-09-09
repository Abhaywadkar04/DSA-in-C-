class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* temp = head;
        
        // Create a 2D vector initialized with -1
        vector<vector<int>> arr(m, vector<int>(n, -1));

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        // Filling the array in spiral order
        while (temp != nullptr) {
            // Fill the top row
            for (int i = left; i <= right && temp != nullptr; i++) {
                arr[top][i] = temp->val;
                temp = temp->next;
            }
            top++;

            // Fill the right column
            for (int i = top; i <= bottom && temp != nullptr; i++) {
                arr[i][right] = temp->val;
                temp = temp->next;
            }
            right--;

            // Fill the bottom row
            for (int i = right; i >= left && temp != nullptr; i--) {
                arr[bottom][i] = temp->val;
                temp = temp->next;
            }
            bottom--;

            // Fill the left column
            for (int i = bottom; i >= top && temp != nullptr; i--) {
                arr[i][left] = temp->val;
                temp = temp->next;
            }
            left++;
        }

        return arr;
    }
};
