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

    void helper(TreeNode* root,vector<int>&nums){
        if(root==nullptr){
            return ;
        }

        helper(root->left,nums);
        helper(root->right,nums);
        nums.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>nums;

        helper(root,nums);

    
         return nums;  
    }
 
};