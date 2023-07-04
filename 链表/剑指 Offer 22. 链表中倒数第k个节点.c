struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    for(int i = 1; i < k ;i++)
    {//快指针先多走k-1步
        fast = fast->next;
    }
    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}