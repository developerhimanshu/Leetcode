//	https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int sz = que.size();
            vector<int>temp;
            for(int i = 0; i<sz; i++){
                auto nod = que.front();
                temp.push_back(nod->val);
                que.pop();
                if(nod->left)que.push(nod->left);
                if(nod->right)que.push(nod->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};