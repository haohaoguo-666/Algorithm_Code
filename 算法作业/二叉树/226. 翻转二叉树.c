struct TreeNode* invertTree(struct TreeNode* root){
    invert(root);
    return root;
}


void invert(struct TreeNode* root){
    if(root == NULL) return;
    struct TreeNode* stmp= root->left;
    root->left = root->right;
    root->right = stmp;
    invert(root->left);
    invert(root->right);
}