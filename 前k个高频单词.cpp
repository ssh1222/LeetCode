//��һ�ǿյĵ����б�����ǰ k �����ִ������ĵ��ʡ�
//���صĴ�Ӧ�ð����ʳ���Ƶ���ɸߵ������������ͬ�ĵ�������ͬ����Ƶ�ʣ�����ĸ˳������
//ʾ�� 1��
//���� : ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// ��� : ["i", "love"]
//  ���� : "i" �� "love" Ϊ���ִ��������������ʣ���Ϊ2�Ρ�
//	   ע�⣬����ĸ˳�� "i" �� "love" ֮ǰ��
//
//	   ʾ�� 2��
//   ���� : ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
//	��� : ["the", "is", "sunny", "day"]
//	 ���� : "the", "is", "sunny" �� "day" �ǳ��ִ��������ĸ����ʣ�
//		  ���ִ�������Ϊ 4, 3, 2 �� 1 �Ρ�
//
//		  ע�⣺
//		  �ٶ� k ��Ϊ��Чֵ�� 1 �� k �� ����Ԫ������
//		  ����ĵ��ʾ���Сд��ĸ��ɡ�
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		map<string, int> countMap;
		vector<string> v;
		for (const auto& e : words)
			++countMap[e];
		multimap<int, string, greater<int>> retMap;
		for (const auto& e : countMap)
			retMap.insert(make_pair(e.second, e.first));
		for (const auto& e : retMap){
			if (k-- > 0)
				v.push_back(e.second);
		}
		return v;
	}
};