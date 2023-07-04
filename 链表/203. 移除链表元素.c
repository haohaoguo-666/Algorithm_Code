//思路一
//带哨兵位的头节点
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *guard = NULL;
    struct ListNode *tail = NULL;
    struct ListNode *cur = head;

    //空链表直接返回NULL
    if(cur == NULL)return NULL;
    //创建哨兵头节点，和tail来指向新链表的尾节点
    guard = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;

    while(cur)
    {
        if(cur->val != val)
        {
            tail->next = cur;
            cur = cur->next;
            tail = tail->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    tail->next = NULL;
    struct ListNode* Newhead = guard->next;
    free(guard);
    return Newhead;

}

//思路二
//双指针
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* tail = head;
	struct ListNode* prev = NULL;
    struct ListNose* newhead = NULL;
	while (tail) {
		//如果不是val
		if (tail->val != val) {
			if(prev == NULL){
                prev = tail;
                newhead = prev;
            }else{
                prev ->next  = tail;
                prev = tail;
            }
			tail = tail->next;
		}
		//如果是val
		else {
			tail = tail->next;
		}
	}
    //如果不是空链表
    if(prev != NULL){
        prev->next = NULL;
    }
	return newhead;
}