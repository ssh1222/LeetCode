//给定一个二叉树，返回它的中序 遍历。
//
//示例 :
//
//输入 : [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//
//输出:[1, 3, 2]

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
typedef struct SeqList{
	int *array;
	int size;
	int capacity;
}   SeqList;

void SeqListInit(SeqList *seqlist, int capacity)
{
	seqlist->array = (int*)malloc(sizeof(int)* capacity);
	seqlist->size = 0;
	seqlist->capacity = capacity;
}

void SeqListCapacity(SeqList *seqlist)
{
	if (seqlist->size < seqlist->capacity)
	{
		return;
	}

	int capacity = seqlist->capacity * 2;
	int *array = (int*)malloc(sizeof(int)* capacity);
	for (int i = 0; i < seqlist->size; ++i){
		array[i] = seqlist->array[i];
	}

	free(seqlist->array);
	seqlist->array = array;
	seqlist->capacity = capacity;
}

void SeqListPushBack(SeqList *seqlist, int val)
{
	SeqListCapacity(seqlist);

	seqlist->array[seqlist->size] = val;
	seqlist->size++;
}

void Inorder(struct TreeNode* root, SeqList *seqlist)
{
	if (root == NULL){
		return;
	}

	Inorder(root->left, seqlist);
	SeqListPushBack(seqlist, root->val);
	Inorder(root->right, seqlist);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	SeqList seqlist;
	SeqListInit(&seqlist, 100);
	Inorder(root, &seqlist);

	*returnSize = seqlist.size;
	return seqlist.array;
}