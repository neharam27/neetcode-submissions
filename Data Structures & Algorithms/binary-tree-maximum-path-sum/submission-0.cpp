class Solution {
public:
    int ans= INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }

        int left= max(0,dfs(root->left));
        int right= max(0,dfs(root->right));

        int path= root->val +right+left;
        ans= max(ans,path);

        return root->val+ max(right,left);
    }
};
