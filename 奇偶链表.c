//给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
//
//请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
//
//示例 1:
//
//输入 : 1->2->3->4->5->NULL
//输出 : 1->3->5->2->4->NULL
//	 示例 2 :
//
// 输入 : 2->1->3->5->6->4->7->NULL
//  输出 : 2->3->6->7->1->5->4->NULL
//   说明 :
//
//	 应当保持奇数节点和偶数节点的相对顺序。
//		 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

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

	struct ListNode *p1 = head;  //指向奇结点
	struct ListNode *p2 = head->next;  //记录第一个偶结点
	struct ListNode *p4;  //记录最后一个偶结点
	while (p1 != NULL){
		struct ListNode *p3 = p1->next;  //指向偶结点
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