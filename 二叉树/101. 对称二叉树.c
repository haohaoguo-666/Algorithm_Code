bool isSymmetricTree(struct TreeNode* root1, struct TreeNode* root2)
{
    if(root1 == NULL && root2 == NULL) return true;

    if(root1 == NULL || root2 == NULL) return false;

    if(root1->val != root2->val) return false;

    return isSymmetricTree(root1->left, root2->right) && 
            isSymmetricTree(root1->right, root2->left);
}

bool isSymmetric(struct TreeNode* root){
    return isSymmetricTree(root->left, root->right);
}