//������������ A �� B �� ��������һ���ɿո�ָ��ĵ��ʡ�ÿ�����ʽ���Сд��ĸ��ɡ���
//
//���һ������������һ��������ֻ����һ�Σ�����һ��������ȴû�г��֣���ô������ʾ��ǲ������ġ�
//
//�������в����õ��ʵ��б�
//
//�����԰��κ�˳�򷵻��б�
//
//
//ʾ�� 1��
//
//���룺A = "this apple is sweet", B = "this apple is sour"
//�����["sweet", "sour"]
//
//
//ʾ�� 2��
//
//���룺A = "apple apple", B = "banana"
//�����["banana"]

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