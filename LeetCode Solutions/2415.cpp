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
    
    void calc(TreeNode*&lefter, TreeNode*&righter, int level){
        if (lefter == NULL || righter == NULL){
            return;
        }
        
        if (level % 2 == 1){
            int val = lefter->val;
            lefter->val = righter->val;
            righter->val = val;
        }
        
        calc(lefter->left, righter->right, level + 1);
        calc(lefter->right, righter->left, level + 1);
        return;
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        calc(root-> left, root->right, 1);
        
        return root;
    }
};
