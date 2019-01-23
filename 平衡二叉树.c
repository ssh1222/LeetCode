//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//
//�����У�һ�ø߶�ƽ�����������Ϊ��
//
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��
//
//ʾ�� 1:
//
//����������[3, 9, 20, null, null, 15, 7]
//
//3
/// \
//9  20
/// \
//15   7
//���� true ��
//
//ʾ�� 2:
//
//����������[1, 2, 2, 3, 3, null, null, 4, 4]
//
//1
/// \
//2   2
/// \
//3   3
/// \
//4   4
//���� false ��

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int Max(int a, int b)
{
	return a > b ? a : b;
}

int GetHeight(struct TreeNode *root)
{
	if (root == NULL){
		return 0;
	}

	return Max(GetHeight(root->left), GetHeight(root->right)) + 1;
}
bool isBalanced(struct TreeNode* root)
{
	if (root == NULL){
		return true;
	}

	int left_height = GetHeight(root->left);
	int right_height = GetHeight(root->right);

	int diff = left_height - right_height;

	if (diff < -1 || diff > 1){
		return false;
	}

	return isBalanced(root->left) && isBalanced(root->right);
}