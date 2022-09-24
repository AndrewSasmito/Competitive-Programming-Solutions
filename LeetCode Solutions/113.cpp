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
    vector<vector<int>> ans;
    void calc (TreeNode*&root, vector<int> cur, int cnt, int tg){
        if (root == NULL){
            return;
        }
        cnt += root -> val;
        cur.push_back(root -> val);
        if (root -> right == NULL && root -> left == NULL){
            if (cnt == tg){
                ans.push_back(cur);
            }
            return;
        }else{
            calc(root -> left, cur, cnt, tg);
            calc(root -> right, cur, cnt, tg);
        }
        

    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <int> v;
        calc(root, v, 0, targetSum);
        return ans;
    }
};
