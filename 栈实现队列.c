//ʹ��ջʵ�ֶ��е����в�����
//
//push(x) --��һ��Ԫ�ط�����е�β����
//pop() --�Ӷ����ײ��Ƴ�Ԫ�ء�
//peek() --���ض����ײ���Ԫ�ء�
//empty() --���ض����Ƿ�Ϊ�ա�
//ʾ�� :
//
//MyQueue queue = new MyQueue();
//
//queue.push(1);
//queue.push(2);
//queue.peek();  // ���� 1
//queue.pop();   // ���� 1
//queue.empty(); // ���� false

class MyQueue {
private:
	stack<int> stack_a;
	stack<int> stack_b;
public:
	/** Initialize your data structure here. */
	MyQueue()
	{

	}

	/** Push element x to the back of queue. */
	void push(int x)
	{
		stack_a.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop()
	{
		if (stack_b.empty())
		{
			int size = stack_a.size();
			for (int i = 0; i < size; ++i)
			{
				int x = stack_a.top();
				stack_a.pop();
				stack_b.push(x);
			}
		}
		int x = stack_b.top();
		stack_b.pop();
		return x;
	}

	/** Get the front element. */
	int peek()
	{
		if (stack_b.empty())
		{
			int size = stack_a.size();
			for (int i = 0; i < size; ++i)
			{
				int x = stack_a.top();
				stack_a.pop();
				stack_b.push(x);
			}
		}
		int x = stack_b.top();
		return x;
	}

	/** Returns whether the queue is empty. */
	bool empty()
	{
		return stack_a.empty() && stack_b.empty();
	}
};
