class Solution {
public:
    int height(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }
        int left= height(root->left);
        int right= height(root->right);

        if(abs(right-left)>1) {
            return -1;
        }
        if(right==-1||left==-1) {
            return -1;
        }
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) !=-1;
    }
};
