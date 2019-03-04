//翻转链表
//递归翻转
SListNode* Test(SListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	SListNode* cur = Test(head->next);//递归翻转
	head->next->next = head;
	head->next = NULL;
	return cur;
}
//头删，头插翻转
SListNode* Test1(SListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	SListNode* newHead = NULL;
	SListNode* node;
	while (head != NULL)
	{
		node = head;//头删
		head = head->next;

		node->next = newHead;//头插
		newHead = node;
	}
	return newHead;
}
//改变指向方法
SListNode* Test2(SListNode *head)
{
	if (head == NULL)
	{
		return head;
	}
	SListNode* p0 = NULL;
	SListNode* p1 = head;
	SListNode* p2 = head->next;
	while (p1 != NULL)
	{
		p1->next = p0;
		p0 = p1;
		p1 = p2;
		if (p2 != NULL)
		{
			p2 = p2->next;
		}
	}
	return p0;
}

