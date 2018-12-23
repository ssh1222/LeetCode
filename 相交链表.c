//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
//
//���������������
//
//
//
//�ڽڵ� c1 ��ʼ�ཻ��
//
//ʾ�� 1��
//
//
//
//���룺intersectVal = 8, listA = [4, 1, 8, 4, 5], listB = [5, 0, 1, 8, 4, 5], skipA = 2, skipB = 3
//�����Reference of the node with value = 8
//������ͣ��ཻ�ڵ��ֵΪ 8 ��ע�⣬��������б��ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ�������� A Ϊ[4, 1, 8, 4, 5]������ B Ϊ[5, 0, 1, 8, 4, 5]���� A �У��ཻ�ڵ�ǰ�� 2 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 3 ���ڵ㡣
//
//
//ʾ�� 2��
//
//
//
//���룺intersectVal = 2, listA = [0, 9, 1, 2, 4], listB = [3, 2, 4], skipA = 3, skipB = 1
//�����Reference of the node with value = 2
//������ͣ��ཻ�ڵ��ֵΪ 2 ��ע�⣬��������б��ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ�������� A Ϊ[0, 9, 1, 2, 4]������ B Ϊ[3, 2, 4]���� A �У��ཻ�ڵ�ǰ�� 3 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 1 ���ڵ㡣
//
//
//ʾ�� 3��
//
//
//
//���룺intersectVal = 0, listA = [2, 6, 4], listB = [1, 5], skipA = 3, skipB = 2
//�����null
//������ͣ��Ӹ��Եı�ͷ��ʼ�������� A Ϊ[2, 6, 4]������ B Ϊ[1, 5]�����������������ཻ������ intersectVal ����Ϊ 0���� skipA �� skipB ����������ֵ��
//���ͣ������������ཻ����˷��� null��
//
//
//ע�⣺
//
//�����������û�н��㣬���� null.
//�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
//�ɼٶ���������ṹ��û��ѭ����
//���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	ListNode* p0 = headA;
	ListNode* p1 = headB;
	int lenA = 0;
	int lenB = 0;
	int lenAB = 0;
	while (p0 != NULL)
	{
		++lenA;
		p0 = p0->next;
	}
	while (p1 != NULL)
	{
		++lenB;
		p1 = p1->next;
	}
	lenAB = lenA - lenB;
	if (lenB > lenA)
	{
		ListNode* p2 = headB;
		headB = headA;
		headA = p2;
		lenAB = lenB - lenA;
	}
	while (lenAB--)
	{
		headA = headA->next;
	}
	while (headB != NULL && headA != NULL)
	{
		if (headA == headB)
		{
			return headA;
		}
		headA = headA->next;
		headB = headB->next;
	}
	return NULL;
}
