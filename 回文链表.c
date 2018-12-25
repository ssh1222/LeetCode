//���ж�һ�������Ƿ�Ϊ��������
//
//ʾ�� 1:
//
//���� : 1->2
//��� : false
//ʾ�� 2 :
//
//���� : 1->2->2->1
//��� : true

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
bool isPalindrome(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	int count = 0;
	struct ListNode* cur = head;
	while (cur != NULL)
	{
		++count;
		cur = cur->next;
	}
	cur = head;
	count = count / 2;
	while (count--)
	{
		cur = cur->next;
	}
	struct ListNode* node = cur;
	cur = NULL;
	struct ListNode* newCur = NULL;;
	while (node != NULL)
	{
		struct ListNode* node1 = node;
		node = node->next;
		node1->next = newCur;
		newCur = node1;
	}
	while (newCur != NULL&&head != NULL)
	{
		if (newCur->val == head->val)
		{
			newCur = newCur->next;
			head = head->next;
		}
		else
		{
			return false;
		}
	}
	return true;
}