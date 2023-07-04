//思路一
//双指针
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


//思路二
//哨兵头节点
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* guard = (struct ListNode*)malloc(sizeof(struct ListNode));
    guard->next = NULL;
    while(cur)
    {
        struct ListNode* prev = guard->next;
        struct ListNode* ptr = cur->next;
        guard->next = cur;
        cur->next = prev;
        cur = ptr;
    }
    struct ListNode* Newhead = guard->next;
    free(guard);
    return Newhead;
}