//https://leetcode.cn/problems/univalued-binary-tree/
bool isUnivalTree(struct TreeNode* root){
    if(root == NULL)return true;//空节点返回true
    //如果节点值不等，返回false
    if(root->left && root->val != root->left->val)
    {
        return false;
    }
    if(root->right && root->val != root->right->val)
    {
        return false;
    }
    else return isUnivalTree(root->left) && isUnivalTree(root->right);
         //返回左右子树是否为单值树
}

