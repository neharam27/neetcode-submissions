class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        dfs(root,k,ans);
        return ans;
    }

    void dfs(TreeNode* root, int& k, int& ans) {
        if(root==nullptr) {
            return;
        }

        dfs(root->left,k,ans);

        k--;

        if(k==0) {
            ans= root->val;
            return;
        }

        dfs(root->right,k,ans);
    } 
};


