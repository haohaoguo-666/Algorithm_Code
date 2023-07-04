//思路一
//快慢双指针
struct ListNode* middleNode(struct ListNode* head){
    if(head == NULL)return NULL;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        //快指针多走一步
        slow = slow->next;
    }
    return slow;
}

