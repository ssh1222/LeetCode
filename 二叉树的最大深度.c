//����һ�����������ҳ��������ȡ�
//
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
//
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//
//	 ʾ����
//	 ����������[3, 9, 20, null, null, 15, 7]��
//
//	 3
//	 / \
//	 9  20
//	 / \
//	 15   7
//	 �������������� 3 ��

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int maxDepth(struct TreeNode* root)
{
	if (root == NULL){
		return 0;
	}

	int leftDepth = maxDepth(root->left);

	int rightDepth = maxDepth(root->right);

	return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}