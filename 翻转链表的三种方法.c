//#include "SList.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//SList list;
//
////�ݹ��β��ͷ��ӡ�����������
//void TailSListPrint(SListNode* SList)
//{
//	if (SList == NULL)
//	{
//		return;
//	}
//	TailSListPrint(SList->next);//�ݹ��ӡ
//	printf("%d ", SList->data);
//}
//
////��ת����
////�ݹ鷭ת
//SListNode* Test(SListNode* head)
//{
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//	SListNode* cur = Test(head->next);//�ݹ鷭ת
//	head->next->next = head;
//	head->next = NULL;
//	return cur;
//}
////ͷɾ��ͷ�巭ת
//SListNode* Test1(SListNode* head)
//{
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//	SListNode* newHead = NULL;
//	SListNode* node;
//	while (head != NULL)
//	{
//		node = head;//ͷɾ
//		head = head->next;
//
//		node->next = newHead;//ͷ��
//		newHead = node;
//	}
//	return newHead;
//}
////�ı�ָ�򷽷�
//SListNode* Test2(SListNode *head)
//{
//	if (head == NULL)
//	{
//		return head;
//	}
//	SListNode* p0 = NULL;
//	SListNode* p1 = head;
//	SListNode* p2 = head->next;
//	while (p1 != NULL)
//	{
//		p1->next = p0;
//		p0 = p1;
//		p1 = p2;
//		if (p2 != NULL)
//		{
//			p2 = p2->next;
//		}
//	}
//	return p0;
//}
//
//int main()
//{
//	SListInit(&list);
//	//ͷ��
//	SListPushFront(&list, 1);
//	SListPushFront(&list, 2);
//	SListPushFront(&list, 3);
//	SListPushFront(&list, 4);
//	SListPushFront(&list, 5);
//	SListPrint(&list);
//
//	//�����ӡ����
//	SListNode* SList = list.first;
//	TailSListPrint(SList);
//	printf("\n");
//
//	//��ת����
//	//�ݹ鷭ת
//	SListNode* head = list.first;
//	SListNode* ret = Test(head);
//	for (; ret != NULL; ret = ret->next)//��ӡ����
//	{
//		printf("%d-->", ret->data);
//	}
//	printf("NULL\n");
//	//ͷɾ��ͷ�巭ת
//	SListNode* ret1 = Test1(head);
//	for (; ret1 != NULL; ret1 = ret1->next)//��ӡ����
//	{
//		printf("%d-->", ret1->data);
//	}
//	printf("NULL\n");
//	//�ı�ָ�򷽷�
//	SListNode* ret2 = Test2(head);
//	for (; ret2 != NULL; ret2 = ret2->next)//��ӡ����
//	{
//		printf("%d-->", ret2->data);
//	}
//	printf("NULL\n");
//
//	//
//	system("pause");
//	return 0;
//}