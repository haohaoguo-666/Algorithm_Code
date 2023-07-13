typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq);

//销毁
void QueueDestory(Queue* pq);

//入队
void QueuePush(Queue* pq, QDataType x);

//出队
void QueuePop(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);

//长度 
int Queuesize(Queue* pq);

//队头
QDataType QueueFront(Queue* pq);

//队尾
QDataType QueueBack(Queue* pq);


void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

void QueueDestory(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;
		free(del);
	}
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;

}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);

	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;

}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->head == pq->tail)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* prev = pq->head;
		pq->head = prev->next;
		free(prev);
	}
	pq->size--;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	/*assert(!QueueEmpty(pq));

	QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;*/

	return pq->size;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
	
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}


typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&obj->q1);
    QueueInit(&obj->q2);

    return obj;
}

void myStackPush(MyStack* obj, int x) {
    if(!QueueEmpty(&obj->q1)) QueuePush(&obj->q1, x);
    else QueuePush(&obj->q2, x);
}

int myStackPop(MyStack* obj) {
    Queue* emptyQ = &obj->q1;
    Queue* nonemptyQ = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        nonemptyQ = &obj->q1;
        emptyQ = &obj->q2;
    }

    //非空队列的前n-个数据导入空队列
    while(QueueSize(nonemptyQ) > 1)
    {
        QueuePush(emptyQ,QueueFront(nonemptyQ));
        QueuePop(nonemptyQ);
    }
    int top = QueueFront(nonemptyQ);
    QueuePop(nonemptyQ);
    return top;
}

int myStackTop(MyStack* obj) {
    if(!QueueEmpty(&obj->q1)) return QueueBack(&obj->q1);
    else return QueueBack(&obj->q2);
}

bool myStackEmpty(MyStack* obj) {
    return (QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2));
}

void myStackFree(MyStack* obj) {
    QueueDestory(&obj->q1);
    QueueDestory(&obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/