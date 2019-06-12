//给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
//
//如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
//
//返回所有不常用单词的列表。
//
//您可以按任何顺序返回列表。
//
//
//示例 1：
//
//输入：A = "this apple is sweet", B = "this apple is sour"
//输出：["sweet", "sour"]
//
//
//示例 2：
//
//输入：A = "apple apple", B = "banana"
//输出：["banana"]

	class Solution {
	public:
		vector<string> uncommonFromSentences(string A, string B)
		{
			A += ' ';
			A += B;
			unordered_map<string, int> map1;
			size_t start = 0;
			size_t pos = 0;
			do{
				pos = A.find(' ', start);
				++map1[A.substr(start, pos - start)];
				start = pos + 1;
			} while (pos != string::npos);

			vector<string> v;
			for (const auto& e : map1){
				if (e.second == 1)
					v.push_back(e.first);
			}
			return v;
		}
	};