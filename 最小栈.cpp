//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//push(x) --将元素 x 推入栈中。
//pop() --删除栈顶的元素。
//top() --获取栈顶元素。
//getMin() --检索栈中的最小元素。
//示例 :
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 - 3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 - 2.

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack()
	{

	}

	void push(int x)
	{
		if (_min.empty() || x <= _min.top())
			_min.push(x);
		_origin.push(x);
	}

	void pop()
	{
		if (_min.top() == _origin.top())
			_min.pop();
		_origin.pop();
	}

	int top()
	{
		return _origin.top();
	}

	int getMin()
	{
		return _min.top();
	}
private:
	stack<int> _origin;
	stack<int> _min;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/