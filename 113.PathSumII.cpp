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
    vector<int>arr;
    vector<vector<int>>res;
    void fn(TreeNode* root,int sum, int targetSum){
       if(root==NULL)return;
        sum+=root->val;
        arr.push_back(root->val);
        if(sum == targetSum && root->left==NULL && root->right == NULL)
            res.push_back(arr);
        fn(root->left, sum, targetSum);
        fn(root->right, sum, targetSum);
        arr.pop_back();
        
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        fn(root,0, targetSum);
        
        return res;
    }
};