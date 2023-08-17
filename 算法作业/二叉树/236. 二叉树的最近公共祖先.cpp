/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//思路一 DFS + 栈
class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if(root == nullptr)
            return false;

        path.push(root);

        if(root == x)
            return true;

        if(getPath(root->left, x, path))
        {
            return true;
        }

        if(getPath(root->right, x, path))
        {
            return true;
        }
        path.pop();
        return false;

        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath, qPath;
        getPath(root, p, pPath);
        getPath(root, q, qPath);

        while(pPath.size() != qPath.size())
        {
            if(pPath.size() > qPath.size())
                pPath.pop();
            else
                qPath.pop();
        }
        while(pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }
};


//思路二 判断是否在左右子树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { 
public:
    bool isInTree(TreeNode* root, TreeNode* x)
    {
        if(root == nullptr)
        {
            return false;
        }
        if(root == x)
        {
            return true;
        }
        return isInTree(root->left, x) || isInTree(root->right, x);
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        if(root == p || root == q)
            return root;
        
        bool pInLeft = isInTree(root->left, p);
        bool pInRight = !pInLeft;

        bool qInLeft = isInTree(root->left, q);
        bool qInRight = !qInLeft;
    
        if((pInLeft && qInRight) || (pInRight && qInLeft))
        {//一个在左子树，一个在右子树
            return root;
        }
        else if(pInLeft && qInLeft)
        {//都在左子树
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {//都在右子树
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};