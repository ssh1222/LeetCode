//�ڴ�СΪ 2N ������ A ���� N + 1 ����ͬ��Ԫ�أ�������һ��Ԫ���ظ��� N �Ρ�
//
//�����ظ��� N �ε��Ǹ�Ԫ�ء�
//ʾ�� 1��
//���룺[1, 2, 3, 3]
//�����3
//ʾ�� 2��
//���룺[2, 1, 2, 5, 3, 2]
//�����2
//ʾ�� 3��
//���룺[5, 1, 5, 2, 5, 3, 5, 4]
//�����5

class Solution {
public:
	int repeatedNTimes(vector<int>& A)
	{
		unordered_map<int, int> map1;
		for (const auto& e : A){
			++map1[e];
		}

		for (const auto& e : map1){
			if (e.second == A.size() / 2)
				return e.first;
		}
		return 0;
	}
};