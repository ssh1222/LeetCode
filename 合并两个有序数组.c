//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明 :
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例 :
//
//输入 :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//
//输出 : [1, 2, 2, 3, 5, 6]

void merge(int* nums1, int m, int* nums2, int n)
{
	int j = 0;
	int max = m + n;
	for (int i = 0; i < max; ++i)
	{
		if (nums1[i] >= nums2[j])
		{
			int k = 0;
			for (k = m; k > i; --k)
			{
				nums1[k] = nums1[k - 1];
			}
			++m;
			nums1[k] = nums2[j];
			++j;
		}
		if (j == n)
		{
			break;
		}
	}
	for (int i = m; i < max; ++i)
	{
		nums1[i] = nums2[j];
		++j;
	}
	for (int i = 0; i < max; ++i)
	{
		printf("%d", nums1[i]);
	}
	printf("\n");
}