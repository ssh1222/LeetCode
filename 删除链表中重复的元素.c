//����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
//
//ʾ�� 1:
//
//���� : 1->1->2
//��� : 1->2
//ʾ�� 2 :
//
//���� : 1->1->2->3->3
//��� : 1->2->3

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
	if (head == NULL)
	{
		return head;
	}
	ListNode* cur = head->next;
	ListNode* prev = head;
	while (prev->next != NULL)
	{
		if (prev->val == cur->val)
		{
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}