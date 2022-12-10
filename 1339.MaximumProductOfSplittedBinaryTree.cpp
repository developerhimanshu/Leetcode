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
    int MOD = 1e9+7;
   long long ts = 0, ans = 0;
    int helper(TreeNode *root){
        if(!root)return 0;
        int sub = root->val + helper(root->left) + helper(root->right);
        ans = max(ans, sub*(ts-sub));
        return sub;
    }
    int maxProduct(TreeNode* root) {
        ts = helper(root);
        helper(root);
        return ans%MOD;
    }
};