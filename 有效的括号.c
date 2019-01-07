//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
//
//��Ч�ַ��������㣺
//
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ע����ַ����ɱ���Ϊ����Ч�ַ�����
//
//ʾ�� 1:
//
//���� : "()"
//��� : true
//	 ʾ�� 2 :
//
// ���� : "()[]{}"
//  ��� : true
//	   ʾ�� 3 :
//
//   ���� : "(]"
//	��� : false
//		 ʾ�� 4 :
//
//	 ���� : "([)]"
//	  ��� : false
//		   ʾ�� 5 :
//
//	   ���� : "{[]}"
//		��� : true

//��������
typedef char SDataType;

//���þ�̬˳���ʵ��ջ
#define MAX (1000000)
typedef struct Stack
{
	SDataType array[MAX];
	int top;
}   Stack;

//��ʼ��
void StackInit(Stack* stack)
{
	stack->top = 0;
}

//����
void StackDestroy(Stack* stack)
{
	stack->top = 0;
}

//��ɾ�Ĳ�
//ֻ�ܴ�ջ������
void StackPush(Stack* stack, SDataType val)
{
	assert(stack);
	assert(stack->top < MAX);

	stack->array[stack->top] = val;
	++stack->top;
}

//ֻ�ܴ�ջ��ɾ��
void StackPop(Stack* stack)
{
	assert(stack);
	assert(stack->top > 0);

	--stack->top;
}

//��ջ��Ԫ��
SDataType StackTop(Stack* stack)
{
	assert(stack);
	assert(stack->top > 0);

	return stack->array[stack->top - 1];
}

//�ж��Ƿ�Ϊ��
int StackEmpty(const Stack* stack)
{
	return stack->top == 0 ? 1 : 0;
}

//����ջ�����ݸ���
int StackSize(const Stack* stack)
{
	return stack->top;
}
bool isValid(char* s)
{
	char* p = s;
	Stack stack;
	StackInit(&stack);
	while (*p != '\0')
	{
		switch (*p)
		{
		case'{':
		case'[':
		case'(':
			StackPush(&stack, *p);
			break;
		case'}':
		case']':
		case')':
		{
				   if (StackEmpty(&stack))
				   {
					   //����������������
					   return false;
				   }
				   char left = StackTop(&stack);
				   StackPop(&stack);
				   if (!((left == '(' && *p == ')')
					   || (left == '[' && *p == ']')
					   || (left == '{' && *p == '}')))
				   {
					   //�������Ų�ƥ��
					   return false;
				   }
		}
			break;
		}
		++p;
	}
	if (!StackEmpty(&stack))
	{
		//�����Ŷ���������
		return false;
	}
	return true;
}