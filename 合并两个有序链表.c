//��������������ϲ�Ϊһ���µ������������ء�
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

//ʾ�������룺1->2->4, 1->3->4
     //�����1->1->2->3->4->4
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	ListNode* p0 = l1;
	ListNode* p1 = l2;
	ListNode* ret = NULL;
	ListNode* retTail = ret;
	while (p0 != NULL && p1 != NULL)
	{
		if (p0->val <= p1->val)
		{
			if (ret == NULL)
			{
				ret = p0;
			}
			else
			{
				retTail->next = p0;
			}
			retTail = p0;
			p0 = p0->next;
		}
		else
		{
			if (ret == NULL)
			{
				ret = p1;
			}
			else
			{
				retTail->next = p1;
			}
			retTail = p1;
			p1 = p1->next;
		}
	}
	if (p0 == NULL)
	{
		retTail->next = p1;
	}
	if (p1 == NULL)
	{
		retTail->next = p0;
	}
	return ret;
}