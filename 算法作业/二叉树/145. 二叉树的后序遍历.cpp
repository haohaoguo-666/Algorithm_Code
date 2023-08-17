//https://leetcode.cn/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> v;
        TreeNode* prev = nullptr;

        while(!st.empty() || cur)
        {   //1. 左路节点
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();

            //2.栈里面取左路节点，左路节点左子树访问完了
            if(top->right == nullptr || top->right == prev)
            {
                v.push_back(top->val);
                st.pop();

                prev = top;
            }
            else
            {
                //3.访问左路节点右子树 -- 子问题
                cur = top->right;
            }
        

          
            
        }

        return v;
    }
};