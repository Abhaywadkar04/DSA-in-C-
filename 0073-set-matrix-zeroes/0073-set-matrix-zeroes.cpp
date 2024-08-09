class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowCount = matrix.size();
    int colCount = matrix[0].size();

    set<int> rowsWithZero;
    set<int> colsWithZero;

    // Step 1: Identify all the zero elements
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (matrix[i][j] == 0) {
                rowsWithZero.insert(i);
                colsWithZero.insert(j);
            }
        }
    }

    // Step 2: Set the entire row to zero where a zero was found
    for (int row : rowsWithZero) {
        for (int j = 0; j < colCount; j++) {
            matrix[row][j] = 0;
        }
    }

    // Step 3: Set the entire column to zero where a zero was found
    for (int col : colsWithZero) {
        for (int i = 0; i < rowCount; i++) {
            matrix[i][col] = 0;
        }
    }
}
    
};