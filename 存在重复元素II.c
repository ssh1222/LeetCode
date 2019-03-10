//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums[i] = nums[j]，并且 i 和 j 的差的绝对值最大为 k。
//
//示例 1:
//
//输入 : nums = [1, 2, 3, 1], k = 3
//输出 : true
//	 示例 2 :
//
// 输入 : nums = [1, 0, 1, 1], k = 1
//  输出 : true
//	   示例 3 :
//
//   输入 : nums = [1, 2, 3, 1, 2, 3], k = 2
//	输出 : false

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
	int left = 0;
	int right = numsSize;
	while (left < right){
		for (int i = left; i < right - 1; i++){
			if (((nums[i + 1] == nums[left] && (i + 1 - left <= k)))
				|| ((nums[i] == nums[right - 1] && (right - 1 - i <= k)))){
				return true;
			}
		}
		left++;
		right--;
	}
	return false;
}