//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//说明 : 叶子节点是指没有子节点的节点。
//
// 示例 :
//
//给定二叉树[3, 9, 20, null, null, 15, 7],
//
//3
/// \
//9  20
/// \
//15   7
//返回它的最小深度  2.

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