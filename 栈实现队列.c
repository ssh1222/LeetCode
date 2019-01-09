//使用栈实现队列的下列操作：
//
//push(x) --将一个元素放入队列的尾部。
//pop() --从队列首部移除元素。
//peek() --返回队列首部的元素。
//empty() --返回队列是否为空。
//示例 :
//
//MyQueue queue = new MyQueue();
//
//queue.push(1);
//queue.push(2);
//queue.peek();  // 返回 1
//queue.pop();   // 返回 1
//queue.empty(); // 返回 false

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
