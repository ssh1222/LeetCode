//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//
//示例 1:
//
//输入 : 1->1->2
//输出 : 1->2
//示例 2 :
//
//输入 : 1->1->2->3->3
//输出 : 1->2->3

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