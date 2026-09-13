
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }

    int dfs(TreeNode* root, int maxval) {
        if (root == nullptr) {
            return 0;
        }
        int count=0;

        if(root->val>=maxval){
            maxval= root->val;
            count=1;     
        }

        count+= dfs(root->left,maxval);
        count+= dfs(root->right, maxval);

        return count;
    }
};
