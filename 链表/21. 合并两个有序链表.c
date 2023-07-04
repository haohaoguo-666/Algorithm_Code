//思路三
//有哨兵位的头节点
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode* guard = NULL, *tail = NULL;
    guard = (struct ListNode*)malloc(sizeof(struct ListNode));
    guard->next = NULL;
    tail = guard;

    //取小的尾插
    while(list1&&list2)
    {
        if(list1->val < list2->val)
        {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }
    if(list1)tail->next = list1;
    if(list2)tail->next = list2;

    struct ListNode* newnode = guard->next;
    free(guard);
    return newnode;

}