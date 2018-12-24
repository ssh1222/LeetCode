//ɾ�������е��ڸ���ֵ val �����нڵ㡣
//
//ʾ�� :
//
//���� : 1->2->6->3->4->5->6, val = 6
//��� : 1->2->3->4->5

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;

struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode* cur = head->next;
	ListNode* prev = head;
	while (cur != NULL)
	{
		if (cur->val != val)
		{
			prev = cur;
		}
		else
		{
			prev->next = cur->next;
			free(cur);
		}
		cur = prev->next;
	}
	ListNode* newHead = head;
	if (newHead->val == val)
	{
		head = newHead->next;
		free(newHead);
	}
	return head;
}