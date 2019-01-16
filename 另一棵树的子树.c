//���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������
//
//ʾ�� 1:
//�������� s :
//
//3
/// \
//4   5
/// \
//1   2
//�������� t��
//
//4
/// \
//1   2
//���� true����Ϊ t �� s ��һ������ӵ����ͬ�Ľṹ�ͽڵ�ֵ��
//
//ʾ�� 2:
//�������� s��
//
//3
/// \
//4   5
/// \
//1   2
///
//0
//�������� t��
//
//4
/// \
//1   2
////���� false��

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSameTree(struct TreeNode *s, struct TreeNode *t)
{
	if (s == NULL && t == NULL){
		return true;
	}

	if (s == NULL || t == NULL){
		return false;
	}

	return s->val == t->val
		&& isSameTree(s->left, t->left)
		&& isSameTree(s->right, t->right);
}

bool preoder(struct TreeNode *s, struct TreeNode *t)
{
	if (s == NULL){
		return false;
	}

	if (isSameTree(s, t)){
		return true;
	}
	if (preoder(s->left, t) == true){
		return true;
	}
	if (preoder(s->right, t) == true){
		return true;
	}
	else{
		return false;
	}
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	return preoder(s, t);
}