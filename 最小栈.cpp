//���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
//push(x) --��Ԫ�� x ����ջ�С�
//pop() --ɾ��ջ����Ԫ�ء�
//top() --��ȡջ��Ԫ�ء�
//getMin() --����ջ�е���СԪ�ء�
//ʾ�� :
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> ���� - 3.
//minStack.pop();
//minStack.top();      --> ���� 0.
//minStack.getMin();   --> ���� - 2.

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