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
    int cnt = -1;
    unordered_map <int, long long> m;
    void dfs(TreeNode* root, int i){
        if (root == NULL){
            return;
        }
        m[i] += root -> val;
        dfs(root -> right, i + 1);
        dfs(root -> left, i + 1);
        cnt = max(i, cnt);
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root, 0);
        vector <long long> v;
        for (int i = 0; i<=cnt; ++i){
            v.push_back(m[i]);
        }
        sort(v.begin(), v.end(), greater<long long>());
        if (v.size() < k){
            return -1;
        }else{
            return v[k - 1];
        }
    }
};
