//ʹ�ö���ʵ��ջ�����в�����
//
//push(x) --Ԫ�� x ��ջ
//pop() --�Ƴ�ջ��Ԫ��
//top() --��ȡջ��Ԫ��
//empty() --����ջ�Ƿ�Ϊ��
//ע�� :
//
//��ֻ��ʹ�ö��еĻ�������-- Ҳ���� push to back, peek / pop from front, size, �� is empty ��Щ�����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���� deque��˫�˶��У���ģ��һ������, ֻҪ�Ǳ�׼�Ķ��в������ɡ�
//����Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������
typedef int QDataType;

//�õ�����ʵ�ֶ���

//������
typedef struct QNode
{
	QDataType val;
	struct QNode* next;
}   QNode;

//����
typedef struct Queue
{
	QNode* front; //ָ������ĵ�һ����㣬�������Ϊ�գ� ==NULL
	QNode* rear;  //ָ����������һ����㣬�������Ϊ�գ�==NULL
	int size;     //��ʾ���������ݸ���
}   Queue;

//��ʼ��/����
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

//��ɾ�Ĳ�
void QueuePush(Queue* queue, QDataType val)
{
	//������
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

//��/size
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
	//obj->queue.size��Ч���ݸ���
	//obj->max_szie������ݸ���
	assert(obj->queue.size < obj->max_size);

	QueuePush(&(obj->queue), x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	assert(obj->queue.size > 0);
	//��Ҫ�ȱ�����size����ѭ�������У�size�ڲ��ϱ仯
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
	//��Ҫ�ȱ�����size����ѭ�������У�size�ڲ��ϱ仯
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