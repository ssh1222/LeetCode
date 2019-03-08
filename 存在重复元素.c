//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//
//����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��
//
//ʾ�� 1:
//
//���� : [1, 2, 3, 1]
//��� : true
//	 ʾ�� 2 :
//
// ���� : [1, 2, 3, 4]
//  ��� : false
//	   ʾ�� 3 :
//
//   ���� : [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
//	��� : true

bool containsDuplicate(int* nums, int numsSize)
{
	int left = 0;
	int right = numsSize;
	while (left < right){
		for (int i = left; i < right - 1; i++){
			if (nums[i + 1] == nums[left] || nums[i] == nums[right - 1]){
				return true;
			}
		}
		left++;
		right--;
	}
	return false;
}