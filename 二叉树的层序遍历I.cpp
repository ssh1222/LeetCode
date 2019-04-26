//给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
//例如 :
//给定二叉树 : [3, 9, 20, null, null, 15, 7],
//	3
//	/ \
//	9  20
//	/ \
//	15   7
//	返回其层次遍历结果：
//	[
//		[3],
//		[9, 20],
//		[15, 7]
//	]

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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		queue<TreeNode*> pNode;
		queue<int> pIdx;
		vector<vector<int>> treeVec;
		treeVec.resize(getHeight(root));

		if (root){
			pNode.push(root);
			pIdx.push(0);
		}

		while (!pNode.empty()){
			TreeNode *cur = pNode.front();
			pNode.pop();
			int curIdx = pIdx.front();
			pIdx.pop();
			treeVec[curIdx].push_back(cur->val);
			if (cur->left){
				pNode.push(cur->left);
				pIdx.push(curIdx + 1);
			}
			if (cur->right){
				pNode.push(cur->right);
				pIdx.push(curIdx + 1);
			}
		}
		return treeVec;
	}
};