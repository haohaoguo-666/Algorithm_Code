//https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> v;
        

        while(!st.empty() || cur)
        {   //1. 左路节点
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            
            //2.栈里面取左路节点，左路节点左子树访问完了
            TreeNode* top = st.top();
            st.pop();
            v.push_back(top->val);

            //3.访问左路节点右子树
            cur = top->right;
        }

        return v;
    }
};