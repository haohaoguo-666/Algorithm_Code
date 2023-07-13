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

void Postorder(struct TreeNode* root, int* a, int* pi)
{
    if(root == NULL) return;
    Postorder(root->left, a, pi);
    Postorder(root->right, a, pi);
    a[(*pi)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    Postorder(root, a, &i);
    return a;
}