struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    //你走过我走过的路，我走过你走过的路
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