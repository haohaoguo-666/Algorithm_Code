//https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> v;
        while(cur || !st.empty())
        {
            //开始访问一个树
            //1.左右节点
            //2.左路节点的右子树
            while(cur)
            {
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            //开始访问右子树
            TreeNode* top = st.top();
            st.pop();
            //子问题访问右子树
            cur = top->right;

        }

        return v;
    }
};