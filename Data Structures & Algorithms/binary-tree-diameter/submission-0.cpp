class Solution {
public:
    int diameter=0;

    int maxdepth(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }

        int left= maxdepth(root->left);
        int right=maxdepth(root->right);
         
        diameter= max(diameter, right+left);
        return 1+ max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root);
        return diameter;
    }
};
