//	https://leetcode.com/problems/count-complete-tree-nodes/description/

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
    int countNodes(TreeNode* root) {
    

        int h_l = 0, h_r = 0;
        TreeNode *ptrl = root, *ptrr = root;
        while(ptrl){
            h_l++;
            ptrl=ptrl->left;
        }
        while(ptrr){
            h_r++;
            ptrr=ptrr->right;
        }

        if(h_l==h_r){
            return (1<<h_l) - 1;
        }else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};