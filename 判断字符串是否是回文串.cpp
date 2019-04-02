//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//示例 1:
//输入 : "A man, a plan, a canal: Panama"
//输出 : true
//	 示例 2 :
// 输入 : "race a car"
//  输出 : false

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
			//从开始找到第一个字母或数字
			while (begin < end){
				if (isNumberorLetter(s[begin]))
					break;
				begin++;
			}
			//从字符串后找到第一个字母或数字
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