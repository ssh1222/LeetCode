//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//
//示例 1:
//
//输入 : nums = [1, 1, 1, 2, 2, 3], k = 2
//输出 : [1, 2]
//
//
//	 示例 2 :
//
// 输入 : nums = [1], k = 1
//  输出 : [1]
//
//	   说明：

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