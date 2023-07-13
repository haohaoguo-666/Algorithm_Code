/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        struct ListNode* guard1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* pre1 = guard1;
        struct ListNode* guard2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* pre2 = guard2;
        struct ListNode* cur = pHead;
        if(cur == NULL) return NULL;
        while(cur)
        {
            if(cur->val >= x)
            {
                pre1->next = cur;
                cur = cur->next;
                pre1 = pre1->next;    
            }
            else
            {
                pre2->next = cur;
                cur = cur->next;
                pre2 = pre2->next;
            }
            
        }
        pre2->next = guard1->next;
        pre1->next = NULL;
        free(guard1);
        struct ListNode* Newhead = guard2->next;
        free(guard2);

        return Newhead;

    }
};