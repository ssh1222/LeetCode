//��ת����
//�ݹ鷭ת
SListNode* Test(SListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	SListNode* cur = Test(head->next);//�ݹ鷭ת
	head->next->next = head;
	head->next = NULL;
	return cur;
}
//ͷɾ��ͷ�巭ת
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
		node = head;//ͷɾ
		head = head->next;

		node->next = newHead;//ͷ��
		newHead = node;
	}
	return newHead;
}
//�ı�ָ�򷽷�
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

