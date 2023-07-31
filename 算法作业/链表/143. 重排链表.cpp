/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode*  head)
    {
        ListNode* node = new ListNode();

        ListNode* cur = head;
        while(cur->next != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = node->next;
            node->next = cur;
            
            cur = next;
        }
        cur->next = node->next;
        delete node;
        return cur;
    }

    void combine(ListNode* head1, ListNode* head2)
    {
        ListNode* left = head1;
        ListNode* right = head2;
        while(left != nullptr && right != nullptr)
        {
            ListNode* left_next = left->next;
            ListNode* right_next = right->next;

            left->next = right;
            left = left_next;

            right->next = left;
            right = right_next;
            
        }
        
    }

    void reorderList(ListNode* head) {
        //只有一个节点
        if(head->next == nullptr)
            return;

        //找到中间节点（尾节点）
        ListNode* mid = findMid(head);

        //翻转右半部分链表,得到新链表
        ListNode* righthead = reverse(mid->next);
        mid->next = nullptr;

        //构建新的链表
        combine(head, righthead);
        
        
    }
};