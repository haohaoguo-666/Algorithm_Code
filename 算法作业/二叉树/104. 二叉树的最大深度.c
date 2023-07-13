int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    int maxleft = maxDepth(root->left);
    int maxright = maxDepth(root->right);
    return maxleft > maxright ? maxleft + 1 : maxright + 1;
}