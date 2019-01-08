//使用队列实现栈的下列操作：
//
//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//注意 :
//
//你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
typedef int QDataType;

//用单链表实现队列

//链表结点
typedef struct QNode
{
	QDataType val;
	struct QNode* next;
}   QNode;

//队列
typedef struct Queue
{
	QNode* front; //指向链表的第一个结点，如果链表为空， ==NULL
	QNode* rear;  //指向链表的最后一个结点，如果链表为空，==NULL
	int size;     //表示队列中数据个数
}   Queue;

//初始化/销毁
void QueueInit(Queue* queue)
{
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

void QueueDestroy(Queue* queue)
{
	QNode* next;
	for (QNode* cur = queue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}

	queue->front = queue->rear = NULL;
	queue->size = 0;
}

//增删改查
void QueuePush(Queue* queue, QDataType val)
{
	//申请结点
	QNode* node = (QNode*)malloc(sizeof(QNode));
	assert(node);
	node->val = val;
	node->next = NULL;
	++queue->size;

	if (queue->rear == NULL)
	{
		queue->front = queue->rear = node;
	}
	else
	{
		queue->rear->next = node;
		queue->rear = node;
	}
}

void QueuePop(Queue* queue)
{
	assert(queue->size > 0);
	--queue->size;

	QNode* old_front = queue->front;
	queue->front = queue->front->next;
	free(old_front);

	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}
}

QDataType QueueFront(const Queue* queue)
{
	assert(queue->size > 0);

	return queue->front->val;
}

//空/size
int QueueEmpty(const Queue* queue)
{
	return queue->size == 0 ? 1 : 0;
}
typedef struct {
	int max_size;
	Queue queue;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize)
{
	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
	assert(stack);
	stack->max_size = maxSize;
	QueueInit(&(stack->queue));

	return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
	//obj->queue.size有效数据个数
	//obj->max_szie最多数据个数
	assert(obj->queue.size < obj->max_size);

	QueuePush(&(obj->queue), x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	assert(obj->queue.size > 0);
	//需要先保存下size，在循环过程中，size在不断变化
	int size = obj->queue.size;
	for (int i = 0; i < size - 1; ++i)
	{
		int x = QueueFront(&(obj->queue));
		QueuePop(&(obj->queue));
		QueuePush(&(obj->queue), x);
	}

	int x = QueueFront(&(obj->queue));
	QueuePop(&(obj->queue));
	return x;
}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
	assert(obj->queue.size > 0);
	//需要先保存下size。在循环过程中，size在不断变化
	int size = obj->queue.size;
	for (int i = 0; i < size - 1; ++i)
	{
		int x = QueueFront(&(obj->queue));
		QueuePop(&(obj->queue));
		QueuePush(&(obj->queue), x);
	}

	int x = QueueFront(&(obj->queue));
	QueuePop(&(obj->queue));
	QueuePush(&(obj->queue), x);

	return x;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&(obj->queue));
}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&(obj->queue));
}