int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void preorder(struct TreeNode* root, int* a, int* pi)
{
    if(root == NULL) return;

    a[(*pi)++] = root->val;
    preorder(root->left, a, pi);
    preorder(root->right, a, pi);
}
 
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    preorder(root, a, &i);
    return a;
}