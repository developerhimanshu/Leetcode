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

    // We are returning the path without split
    int dfs(TreeNode *root, int& res){
        if(!root)return 0;
        int lmax = dfs(root->left, res);
        int rmax = dfs(root->right, res);
        lmax = max(lmax, 0);
        rmax = max(rmax, 0);
        res = max(res, root->val+lmax+rmax);  // we are computing the path with split

        return root->val+max(lmax, rmax);
    }
    int maxPathSum(TreeNode* root) {
        int res = root->val;
         dfs(root, res);
        return res;
    }
};