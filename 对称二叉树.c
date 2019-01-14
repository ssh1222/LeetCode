//����һ����������������Ƿ��Ǿ���ԳƵġ�
//
//���磬������[1, 2, 2, 3, 4, 4, 3] �ǶԳƵġ�
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//�����������[1, 2, 2, null, 3, null, 3] ���Ǿ���ԳƵ�:
//
//1
/// \
//2   2
//\   \
//3    3

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isMirror(struct TreeNode *p, struct TreeNode *q)
{
	if (p == NULL && q == NULL){
		return true;
	}

	if (p == NULL || q == NULL){
		return false;
	}

	return p->val == q->val
		&& isMirror(p->left, q->right)
		&& isMirror(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL){
		return true;
	}

	return isMirror(root->left, root->right);
}