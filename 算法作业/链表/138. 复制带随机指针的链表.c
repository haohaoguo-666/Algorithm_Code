/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

// struct Node* copyRandomList(struct Node* head) {
// 	struct Node* cur = head;
//     struct Node* phead = NULL;//新的链表头指针
//     struct Node* pprev = NULL;//新的链表前结点指针
//     struct Node* pcur = NULL;//新的链表当前结点指针
//     while(cur)
//     {
       
//         pcur = (struct Node*)malloc(sizeof(struct Node));
//         if(pprev)pprev->next = pcur;
//         pprev = pcur;
//         if(phead == NULL)phead = pcur;
//         pcur->val = cur->val;
//         cur = cur->next;

//     }
//     pcur->next = NULL;
    
//     return phead;

// }

struct Node* copyRandomList(struct Node* head) {
    if(head==NULL)return NULL;
	struct Node* cur = head;
    while(cur)//插入结点
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = cur->val;
        newnode->next = cur->next;
        cur->next = newnode;
        cur = cur->next->next;
    }
    cur = head;
    while(cur)//填充random
    {
        if(cur->random)
        {
            cur->next->random = cur->random->next;
        }
        else
        {
            cur->next->random = NULL;
        }
        cur = cur->next->next;
    }
    struct Node* phead = head->next;
    cur = head->next;
    while(cur->next)
    {
        cur->next = cur->next->next;
        cur= cur->next;
    }
    return phead;

}