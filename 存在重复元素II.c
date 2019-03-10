//����һ�����������һ������ k���ж��������Ƿ����������ͬ������ i �� j��ʹ�� nums[i] = nums[j]������ i �� j �Ĳ�ľ���ֵ���Ϊ k��
//
//ʾ�� 1:
//
//���� : nums = [1, 2, 3, 1], k = 3
//��� : true
//	 ʾ�� 2 :
//
// ���� : nums = [1, 0, 1, 1], k = 1
//  ��� : true
//	   ʾ�� 3 :
//
//   ���� : nums = [1, 2, 3, 1, 2, 3], k = 2
//	��� : false

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