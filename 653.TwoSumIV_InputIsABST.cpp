//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    bool preorder(TreeNode* root, int k, unordered_set<int>&mp){
        if(root == NULL)return false;
        if(mp.find(k-root->val)!=mp.end())return true;
        else
            mp.insert(root->val);
        return preorder(root->left, k, mp)||preorder(root->right, k, mp);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root->left ==NULL && root->right == NULL)return false;
        unordered_set<int>mp;
       return  preorder(root,k, mp);
       
    }
};