//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//
//����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��
//
//ʾ�� 1:
//
//���� : [1, 2, 3, 1]
//��� : true

class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		unordered_set<int> s1;
		for (const auto& e : nums){
			if (!(s1.insert(e)).second)
				return true;
		}
		return false;
	}
};