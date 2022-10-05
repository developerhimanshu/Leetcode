//https://leetcode.com/problems/add-one-row-to-tree/description/

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // TreeNode*newRoot;
         if(depth==1)  // If we have to insert at 1st depth then we'll just add the root to new node's left
            return new TreeNode(val, root, NULL);//This means give the left as root and right as NULL
        queue<TreeNode*>q;
        int count = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode *temp = q.front();
                q.pop();
               
                if(count+2 == depth){  // This means we are at position where we have to insert at its next  
                    temp->left = new TreeNode(val, temp->left, nullptr); // Insert the val at the left
                    temp->right = new TreeNode(val, nullptr, temp->right); // Insert the val at the right
                }
                else{
                    if(temp->left)q.push(temp->left);
                    if(temp->right)q.push(temp->right);
                }
            }
            count++;
        }
        return root;
    }
};