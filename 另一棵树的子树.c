//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
//
//示例 1:
//给定的树 s :
//
//3
/// \
//4   5
/// \
//1   2
//给定的树 t：
//
//4
/// \
//1   2
//返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
//
//示例 2:
//给定的树 s：
//
//3
/// \
//4   5
/// \
//1   2
///
//0
//给定的树 t：
//
//4
/// \
//1   2
////返回 false。

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