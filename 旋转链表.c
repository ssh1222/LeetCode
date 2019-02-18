//����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����
//
//ʾ�� 1:
//
//���� : 1->2->3->4->5->NULL, k = 2
//��� : 4->5->1->2->3->NULL
// ���� :
//������ת 1 �� : 5->1->2->3->4->NULL
//������ת 2 �� : 4->5->1->2->3->NULL
//ʾ�� 2 :
//
//���� : 0->1->2->NULL, k = 4
// ��� : 2->0->1->NULL
//  ���� :
//������ת 1 �� : 2->0->1->NULL
//������ת 2 �� : 1->2->0->NULL
//������ת 3 �� : 0->1->2->NULL
//������ת 4 �� : 2->0->1->NULL

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