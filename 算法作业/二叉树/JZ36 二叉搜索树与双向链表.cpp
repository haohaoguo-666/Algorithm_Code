//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include <sys/types.h>
class Solution {
public:

	void InOrder(TreeNode* cur, TreeNode*& prev)
	{
		if(cur == nullptr)
			return;

		InOrder(cur->left, prev);
		cur->left = prev;
		if(prev)
		{
			prev->right = cur;
		}
		prev = cur;
		InOrder(cur->right, prev);
		
	}
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* prev = nullptr;

		InOrder(pRootOfTree, prev);
		
		TreeNode* head = pRootOfTree;
		while(head && head->left)
		{
			head = head->left;
		}

		return head;

    }
};
