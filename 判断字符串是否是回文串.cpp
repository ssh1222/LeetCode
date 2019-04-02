//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//ʾ�� 1:
//���� : "A man, a plan, a canal: Panama"
//��� : true
//	 ʾ�� 2 :
// ���� : "race a car"
//  ��� : false

class Solution {
public:
	bool isNumberorLetter(char c)
	{
		if (c <= '9' && c >= '0'
			|| c <= 'z' && c >= 'a')
			return true;
		return false;
	}

	bool isPalindrome(string s)
	{
		if (s.empty())
			return true;
		for (auto& e : s){
			if (e <= 'Z' && e >= 'A')
				e = e + 32;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end){
			//�ӿ�ʼ�ҵ���һ����ĸ������
			while (begin < end){
				if (isNumberorLetter(s[begin]))
					break;
				begin++;
			}
			//���ַ������ҵ���һ����ĸ������
			while (begin < end){
				if (isNumberorLetter(s[end]))
					break;
				end--;
			}
			if (begin < end){
				if (s[begin] != s[end])
					return false;
				begin++;
				end--;
			}
		}
		return true;
	}
};