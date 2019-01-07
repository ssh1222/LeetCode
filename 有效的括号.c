//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//
//示例 1:
//
//输入 : "()"
//输出 : true
//	 示例 2 :
//
// 输入 : "()[]{}"
//  输出 : true
//	   示例 3 :
//
//   输入 : "(]"
//	输出 : false
//		 示例 4 :
//
//	 输入 : "([)]"
//	  输出 : false
//		   示例 5 :
//
//	   输入 : "{[]}"
//		输出 : true

//数据类型
typedef char SDataType;

//利用静态顺序表实现栈
#define MAX (1000000)
typedef struct Stack
{
	SDataType array[MAX];
	int top;
}   Stack;

//初始化
void StackInit(Stack* stack)
{
	stack->top = 0;
}

//销毁
void StackDestroy(Stack* stack)
{
	stack->top = 0;
}

//增删改查
//只能从栈顶插入
void StackPush(Stack* stack, SDataType val)
{
	assert(stack);
	assert(stack->top < MAX);

	stack->array[stack->top] = val;
	++stack->top;
}

//只能从栈顶删除
void StackPop(Stack* stack)
{
	assert(stack);
	assert(stack->top > 0);

	--stack->top;
}

//返栈顶元素
SDataType StackTop(Stack* stack)
{
	assert(stack);
	assert(stack->top > 0);

	return stack->array[stack->top - 1];
}

//判断是否为空
int StackEmpty(const Stack* stack)
{
	return stack->top == 0 ? 1 : 0;
}

//返回栈内数据个数
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
					   //左括号少于右括号
					   return false;
				   }
				   char left = StackTop(&stack);
				   StackPop(&stack);
				   if (!((left == '(' && *p == ')')
					   || (left == '[' && *p == ']')
					   || (left == '{' && *p == '}')))
				   {
					   //左右括号不匹配
					   return false;
				   }
		}
			break;
		}
		++p;
	}
	if (!StackEmpty(&stack))
	{
		//左括号多于右括号
		return false;
	}
	return true;
}