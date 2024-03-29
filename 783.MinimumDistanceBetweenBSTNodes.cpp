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
    void dfs(TreeNode*root, vector<int>&v){
        if(root==NULL)return ;
        v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        dfs(root, v);
        int miniAns = INT_MAX;
        for(int i = 0; i<v.size(); i++){
            for(int j = i+1; j<v.size(); j++){
                miniAns = min(miniAns, abs(v[j]-v[i]));
            }
        }
        return miniAns;
    }
};