//给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//例如：
//给定二叉树[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//返回其自底向上的层次遍历为：
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int getHeight(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		int left = getHeight(root->left);
		int right = getHeight(root->right);

		return left > right ? left + 1 : right + 1;
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		queue<TreeNode*> pNode;
		queue<int> pIdx;
		vector<vector<int>> treeVec;
		treeVec.resize(getHeight(root));

		if (root){
			pNode.push(root);
			pIdx.push(treeVec.size() - 1);
		}

		while (!pNode.empty()){
			TreeNode *cur = pNode.front();
			pNode.pop();
			int curIdx = pIdx.front();
			pIdx.pop();
			treeVec[curIdx].push_back(cur->val);

			if (cur->left){
				pNode.push(cur->left);
				pIdx.push(curIdx - 1);
			}
			if (cur->right){
				pNode.push(cur->right);
				pIdx.push(curIdx - 1);
			}
		}
		return treeVec;
	}
};