/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int TreeHeight(struct TreeNode* root)
{
	if (!root) return 0;
	
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

bool isBalanced(struct TreeNode* root){
    if(root ==  NULL)return true;
    int height = TreeHeight(root-> left) - TreeHeight(root->right);
    if(height < -1 || height > 1)
    {
        return false;
    }
    else
    {
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
}