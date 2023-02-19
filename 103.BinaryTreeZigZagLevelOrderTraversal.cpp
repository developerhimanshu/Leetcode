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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }   
        q.push({root, 0});

        vector<int>temp;
        int level = 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(x.second != level){
                if(level%2)reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                temp.clear();
                level = x.second;
            }
            TreeNode * Node = x.first;
            temp.push_back(Node->val);
            if(Node->left)q.push({Node->left, (level+1)});
            if(Node->right)q.push({Node->right, (level+1)});
        }
        if(level%2)
            reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        return ans;
    }
};