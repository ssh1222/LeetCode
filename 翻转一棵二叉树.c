//翻转一棵二叉树。
//
//示例：
//
//输入：
//
//4
/// \
//2     7
/// \ / \
//1   3 6   9
//输出：
//
//4
/// \
//7     2
/// \ / \
//9   6 3   1

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root == NULL){
		return NULL;
	}
	struct TreeNode *left = root->left;
	struct TreeNode *right = root->right;
	root->left = invertTree(right);
	root->right = invertTree(left);
	return root;
}