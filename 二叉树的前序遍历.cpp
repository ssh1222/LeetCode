//给定一个二叉树，返回它的 前序 遍历。
//示例 :
//输入 : [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//
//输出:[1, 2, 3]

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
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> vet;
		stack<TreeNode*> st;
		TreeNode *cur = root;
		while (cur || !st.empty()){
			while (cur){
				st.push(cur);
				vet.push_back(cur->val);
				cur = cur->left;
			}

			cur = st.top();
			st.pop();
			cur = cur->right;
		}

		return vet;
	}
};