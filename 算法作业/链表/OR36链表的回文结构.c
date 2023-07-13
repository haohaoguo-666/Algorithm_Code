/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//大概做法：找出中间节点，从中间位置分割成AB两个链表，让B链表逆序，然后AB链表同时遍历val值，不相等就不是回文链表
//具体：1.先找出链表的中间节点(使用快慢指针) 注意考虑 偶数节点，奇数节点时，中间节点的取值
class PalindromeList {
public:
    struct ListNode* middleNode(struct ListNode* head){
        if(head == NULL)return NULL;
        struct ListNode* fast = head;
        struct ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* rhead = NULL;
    while (cur) {
        //next指向下一个节点
        struct ListNode* next = cur->next;
        //head节点头插入
        cur ->next = rhead;
        //rhead指针指向新的头节点
        rhead = cur;
        //head指针指向新的头节点
        cur = next;
    }
    return rhead;

    }
    bool chkPalindrome(ListNode* A) {
    //    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(ListNode));//哨兵结点

    //    dummy-> next = A;
    //    struct ListNode* fast = dummy;
    //    struct ListNode* slow = dummy;
    //    while(fast && fast->next)//获取中间结点
    //    {
    //     slow = slow -> next;
    //     fast = fast -> next -> next;
    //    }


    //    struct ListNode* cur = slow->next;//反转链表
    //    struct ListNode* pre = slow;
    //    struct ListNode* next = cur;
    //    slow -> next = NULL;
       
    //    while(1)
    //    {
    //     next = cur -> next;
    //     cur -> next = pre;
    //     pre = cur;
    //     if(next==NULL)break;
    //     cur = next;
        
    //    }

    //     struct ListNode* head = A;
    //     struct ListNode* tail = cur;
    //     while(tail != slow)
    //     {
    //         if(head -> val !=  tail -> val)
    //         {
    //             return false;
    //         }
    //         tail = tail -> next;
    //         head = head -> next;
    //     }
    //     return true;
        struct ListNode* mid = middleNode(A);
        struct ListNode* rhead = reverseList(mid);
        while(A && rhead)
        {
            if(A->val != rhead->val) return false;
            A = A->next;
            rhead = rhead->next;
        }
        return true;


    }
};