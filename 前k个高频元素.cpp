//����һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ�ء�
//
//ʾ�� 1:
//
//���� : nums = [1, 1, 1, 2, 2, 3], k = 2
//��� : [1, 2]
//
//
//	 ʾ�� 2 :
//
// ���� : nums = [1], k = 1
//  ��� : [1]
//
//	   ˵����

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		map<int, int> m;
		vector<int> v, ret;
		for (auto e : nums)
			m[e]++;
		for (auto e : m)
			v.push_back(e.second);
		priority_queue<int> p(v.begin(), v.end());
		for (int i = 0; i < k; ++i){
			for (auto e : m){
				if (e.second == p.top()){
					ret.push_back(e.first);
					m.erase(e.first);
					break;
				}
			}
			p.pop();
		}

		return ret;
	}
};