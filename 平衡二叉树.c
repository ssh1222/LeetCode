//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
//
//示例 1:
//
//给定二叉树[3, 9, 20, null, null, 15, 7]
//
//3
/// \
//9  20
/// \
//15   7
//返回 true 。
//
//示例 2:
//
//给定二叉树[1, 2, 2, 3, 3, null, null, 4, 4]
//
//1
/// \
//2   2
/// \
//3   3
/// \
//4   4
//返回 false 。

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