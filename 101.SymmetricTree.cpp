class Solution {
public:
    bool findSymm(TreeNode *r1, TreeNode *r2){
        if(r1== NULL && r2 == NULL)return true;
        else if(r1 == NULL)return false;
        else if(r2 == NULL)return false;

        if(r1->val != r2->val)return false;

        return findSymm(r1->left, r2->right) && findSymm(r1->right, r2->left);

    }
    bool isSymmetric(TreeNode* root) {
       return findSymm(root->left, root->right);
       queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode *leftTree = q.front();
            q.pop();
            TreeNode *rightTree = q.front();
            q.pop();
            if(leftTree == NULL && rightTree == NULL)continue;
            
            if(leftTree==NULL||rightTree==NULL||leftTree->val != rightTree->val)return false;
            q.push(leftTree->left);
            q.push(rightTree->right);
            q.push(leftTree->left);
            q.push(rightTree->right);
        }
        return true;

    }
};