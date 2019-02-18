//����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�
//
//�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������
//
//ʾ�� 1:
//
//���� : 1->2->3->4->5->NULL
//��� : 1->3->5->2->4->NULL
//	 ʾ�� 2 :
//
// ���� : 2->1->3->5->6->4->7->NULL
//  ��� : 2->3->6->7->1->5->4->NULL
//   ˵�� :
//
//	 Ӧ�����������ڵ��ż���ڵ�����˳��
//		 ����ĵ�һ���ڵ���Ϊ�����ڵ㣬�ڶ����ڵ���Ϊż���ڵ㣬�Դ����ơ�

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* oddEvenList(struct ListNode* head)
{
	if (head == NULL){
		return NULL;
	}

	if (head->next == NULL || head->next->next == NULL){
		return head;
	}

	struct ListNode *p1 = head;  //ָ������
	struct ListNode *p2 = head->next;  //��¼��һ��ż���
	struct ListNode *p4;  //��¼���һ��ż���
	while (p1 != NULL){
		struct ListNode *p3 = p1->next;  //ָ��ż���
		if (p3 != NULL && p3->next != NULL){
			p1->next = p3->next;
			p4 = p3;
			p3->next = p3->next->next;
		}
		else{
			p1->next = p2;
			if (p3 == NULL){
				p4->next = NULL;
				break;
			}

			if (p3->next == NULL){
				break;
			}
		}

		p1 = p1->next;
	}
	return head;
}