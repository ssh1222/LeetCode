//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入 : 1->2->3->4->5->NULL, k = 2
//输出 : 4->5->1->2->3->NULL
// 解释 :
//向右旋转 1 步 : 5->1->2->3->4->NULL
//向右旋转 2 步 : 4->5->1->2->3->NULL
//示例 2 :
//
//输入 : 0->1->2->NULL, k = 4
// 输出 : 2->0->1->NULL
//  解释 :
//向右旋转 1 步 : 2->0->1->NULL
//向右旋转 2 步 : 1->2->0->NULL
//向右旋转 3 步 : 0->1->2->NULL
//向右旋转 4 步 : 2->0->1->NULL

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* rotateRight(struct ListNode* head, int k)
{
	if (head == NULL){
		return NULL;
	}
	if (head->next == NULL){
		return head;
	}
	struct ListNode *last = head;
	int count = 0;
	while (last != NULL){
		count++;
		last = last->next;
	}
	k = k % count;
	while (k--){
		struct ListNode *cur = head;
		while (cur->next->next != NULL){
			cur = cur->next;
		}
		cur->next->next = head;
		head = cur->next;
		cur->next = NULL;
	}
	return head;
}