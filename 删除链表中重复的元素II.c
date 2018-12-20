//����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�
//
//ʾ�� 1:
//
//���� : 1->2->3->3->4->4->5
//��� : 1->2->5
//ʾ�� 2 :
//
//���� : 1->1->1->2->3
//��� : 2->3

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* p0 = NULL;
	ListNode* p1 = head;
	ListNode* p2 = head->next;
	ListNode* p3 = NULL;
	while (p2 != NULL)
	{
		if (p1->val != p2->val)
		{
			if (p1->next == p2)
			{
				if (p0 == NULL)
				{
					p3 = p1;
				}
				p0 = p1;
				p1 = p2;
				p2 = p2->next;
			}
			else
			{
				if (p0 == NULL && p2 != head->next)
				{
					p1 = p2;
					p2 = p2->next;
				}
				else
				{
					p0->next = p2;
					p1 = p2;
					p2 = p2->next;
				}
				if (p0 == NULL)
				{
					p3 = p1;
				}
			}
		}
		else
		{
			p2 = p2->next;
		}
	}
	if (p1 == p3 && p1->next == NULL)
	{
		return p1;
	}
	if (p0 == NULL)
	{
		return NULL;
	}
	if (p1->next != NULL)
	{
		p0->next = NULL;
	}
	return p3;
}