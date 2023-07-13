/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode *detectCycle(struct ListNode *head) {
    //快慢指针+数学推理
    // struct ListNode* fast = head;
    // struct ListNode* slow = head;
    // while(true)
    // {
    //     if(fast==NULL || fast -> next == NULL)return NULL;
    //     fast = fast -> next -> next;
    //     slow = slow -> next;
    //     if(fast == slow)break;
    // }

    // fast = head;
    // while(fast != slow)
    // {
    //     fast = fast -> next;
    //     slow = slow -> next;
    // }
    // return fast;
//}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }
    struct ListNode* A = headA;
    struct ListNode* B = headB;
    while(A != B)
    {
        A = A != NULL ? A -> next: headB;
        B = B != NULL ? B -> next: headA;
    }
    return A;


}
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* overhead = NULL;
    while(true)
    {
        if(fast==NULL || fast -> next == NULL)return NULL;
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow)
        {
            struct ListNode* meet = fast;
            overhead = meet->next;
            meet->next = NULL;
            break;
        }

    }
    struct ListNode* cur = getIntersectionNode(head, overhead);
    return cur;
}
