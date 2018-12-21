//����һ�������ж��������Ƿ��л���
//
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л���
//
//
//
//ʾ�� 1��
//
//���룺head = [3, 2, 0, -4], pos = 1
//�����true
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
//
//
//ʾ�� 2��
//
//���룺head = [1, 2], pos = 0
//�����true
//���ͣ���������һ��������β�����ӵ���һ���ڵ㡣

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;

bool hasCycle(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	ListNode* fast = head->next;
	ListNode* slow = head;
	while (fast != slow)
	{
		if (fast->next == NULL || fast->next->next == NULL)
		{
			return false;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return true;
}
