/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void Inorder(struct TreeNode* root, int* a, int* pi)
{
    if(root == NULL) return;
    Inorder(root->left, a, pi);
    a[(*pi)++] = root->val;
    Inorder(root->right, a, pi);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    Inorder(root, a, &i);
    return a;
}

