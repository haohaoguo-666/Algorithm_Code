//https://leetcode.cn/problems/construct-string-from-binary-tree/description/
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
    string tree2str(TreeNode* root) {
        string str;
        if(root == nullptr)
            return "";
        else
        {
            str += to_string(root->val);
            if(root->left || root->right)
            {//左子树不为空必定加（），如果右子树也为空就不加（）
                str += "(";
                str += tree2str(root->left);
                str += ")";
            }

            if(root->right)
            {//右子树为空就不加（）
                str += "(";
                str += tree2str(root->right);
                str += ")";                
            }

        }

        return str;
    }
};