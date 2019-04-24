//ʹ�ö���ʵ��ջ�����в�����
//push(x) --Ԫ�� x ��ջ
//pop() --�Ƴ�ջ��Ԫ��
//top() --��ȡջ��Ԫ��
//empty() --����ջ�Ƿ�Ϊ��
//ע�� :
//��ֻ��ʹ�ö��еĻ�������-- Ҳ���� push to back, peek / pop from front, size, �� is empty ��Щ�����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���� deque��˫�˶��У���ģ��һ������, ֻҪ�Ǳ�׼�Ķ��в������ɡ�
//����Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack()
	{

	}

	/** Push element x onto stack. */
	void push(int x)
	{
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		int size = q.size();
		while (--size){
			q.push(q.front());
			q.pop();
		}
		int val = q.front();
		q.pop();
		return val;
	}

	/** Get the top element. */
	int top()
	{
		return q.back();
	}

	/** Returns whether the stack is empty. */
	bool empty()
	{
		return q.empty();
	}
private:
	queue<int> q;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/