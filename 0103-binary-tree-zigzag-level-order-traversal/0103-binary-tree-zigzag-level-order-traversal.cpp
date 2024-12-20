/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

       vector<vector<int>>answer;
       if(root==nullptr) return answer;

       queue<TreeNode*>nodeQueue;
       nodeQueue.push(root);
       bool lTOr=true;

       while(!nodeQueue.empty()){
        int size=nodeQueue.size();
        vector<int>row(size);

        for(int i=0;i<size;i++){
        TreeNode* temp=nodeQueue.front();
        nodeQueue.pop();

        int index=(lTOr) ? i:(size-1-i);

        row[index]=temp->val;
        if(temp->left){
            nodeQueue.push(temp->left);
        }
        if(temp->right){
            nodeQueue.push(temp->right);
        }
        

        }
        answer.push_back(row);
        lTOr=!lTOr;
       }
       return answer;

    }
};