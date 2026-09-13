class Solution {
public:
    int preindex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left> right) {
            return nullptr;
        }

        int value= preorder[preindex];
        preindex++;

        TreeNode* root= new TreeNode(value);
         int index= left;

        while(inorder[index] != value) {
            index++;
        }

        root->left= build(preorder,inorder, left, index-1);
        root->right=  build(preorder, inorder, index+1, right);

        return root;
    }
};
