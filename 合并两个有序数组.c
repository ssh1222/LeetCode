//�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣
//
//˵�� :
//
//��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
//����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
//ʾ�� :
//
//���� :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//
//��� : [1, 2, 2, 3, 5, 6]

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