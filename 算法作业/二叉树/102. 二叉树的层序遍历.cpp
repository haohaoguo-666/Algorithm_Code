//https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
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

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        int levelsize = 0;
        if(root)
        {
            qu.push(root);
            levelsize = 1; 
        }
        
        int i = 0;
        while(!qu.empty())
        {
            vector<int> v;
            while(levelsize--)
            {
                TreeNode* front = qu.front();
                qu.pop();

                v.push_back(front->val);
                

                if(front->left)
                {
                    qu.push(front->left);
                }

                if(front->right)
                {
                    qu.push(front->right);
                }
            }
            ans.push_back(v);
            levelsize = qu.size();
            
        }

        return ans;
    }
};