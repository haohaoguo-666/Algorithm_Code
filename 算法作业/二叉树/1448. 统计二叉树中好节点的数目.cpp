/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int _goodNodes(TreeNode *root, int mx = INT_MIN) {
        if (root == nullptr)
            return 0;
        int left = _goodNodes(root->left, max(mx, root->val));
        int right = _goodNodes(root->right, max(mx, root->val));
        return left + right + (mx <= root->val);
    }

    int goodNodes(TreeNode* root) {
       
        return _goodNodes(root);
        
    }
};