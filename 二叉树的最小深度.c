//����һ�����������ҳ�����С��ȡ�
//
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
//
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//
// ʾ�� :
//
//����������[3, 9, 20, null, null, 15, 7],
//
//3
/// \
//9  20
/// \
//15   7
//����������С���  2.

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int minDepth(struct TreeNode* root)
{
	if (root == NULL){
		return 0;
	}

	int left = minDepth(root->left);
	int right = minDepth(root->right);

	if (left && right){
		return 1 + (left < right ? left : right);
	}
	return 1 + left + right;
}