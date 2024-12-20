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

      void  swapingTheOddLevel(TreeNode* node1,TreeNode* node2,int level){
            if(node1==nullptr || node2==nullptr){
                return;
            }

            if(level % 2==0) swap(node1->val,node2->val);

            swapingTheOddLevel(node1->left,node2->right,level+1);
            swapingTheOddLevel(node1->right,node2->left,level+1);


        }
        
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

swapingTheOddLevel(root->left,root->right,0);
return root;


        

        


        
    }
};