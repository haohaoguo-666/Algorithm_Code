bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL) return true;//两个都为空节点
    else if(p == NULL || q == NULL)return false;//其中一个为空节点

    if(p->val == q->val)return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    //如果两个节点相等，则比较左右子树
    else return false;
    //两个节点不相等
}