//����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�
//ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� 
//O(1) ����ռ����������ɡ�

/*
C���������鳤�ȣ�sizeof(a)/sizeof(a[0])
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
����Ĵ�������,������Ҫ�����޸ĺ��������ڴ�
*/

//����һ
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0){
		return 0;
	}
	int i = 0;
	int j;
	int account = 1;
	for (j = 1; j<numsSize; j++){
		if (nums[j] != nums[i]){
			account = account + 1;
			i = i + 1;
			nums[i] = nums[j];
		}
	}
	return account;
}

//������
int removeDuplicates(int* nums, int numsSize)
{
	int i = 1;
	int j = 0;
	if (numsSize == 0)
	{
		return j;
	}
	if (numsSize == 1)
	{
		return i;
	}
	while (i < numsSize)
	{
		if (nums[j] != nums[i])
		{
			if (j + 1 == i)
			{
				++i;
				++j;
			}
			else
			{
				nums[++j] = nums[i];
			}
		}
		else
		{
			++i;
		}
	}
	return j + 1;
}