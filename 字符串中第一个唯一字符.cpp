//����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� - 1��
//���� :
//s = "leetcode"
//���� 0.
//
//s = "loveleetcode",
//���� 2.
//
//ע����������Լٶ����ַ���ֻ����Сд��ĸ��

class Solution {
public:
	int firstUniqChar(string s)
	{
		int arr[26] = { 0 };
		int i;
		for (auto& e : s){
			arr[e - 'a']++;
		}
		for (i = 0; i < s.size(); i++){
			if (arr[s[i] - 'a'] == 1){
				return i;
			}
		}
		return -1;
	}
};