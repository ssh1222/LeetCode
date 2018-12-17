//给定一个排序数组，你需要在原地删除重复出现的元素，
//使得每个元素只出现一次，返回移除后数组的新长度。

//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 
//O(1) 额外空间的条件下完成。

/*
C语言求数组长度：sizeof(a)/sizeof(a[0])
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
输出的答案是数组,所以需要考虑修改后的数组等于答案
*/

//方法一
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

//方法二
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