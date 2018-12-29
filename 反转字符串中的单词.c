//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//示例 1:
//
//输入 : "Let's take LeetCode contest"
//输出 : "s'teL ekat edoCteeL tsetnoc"

void Swap(char* x, char* y)
{
	char tmp = *x;
	*x = *y;
	*y = tmp;
}

char* reverseWords(char* s)
{
	int len = strlen(s);
	int left = 0;
	int right = 0;
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == ' ')
		{
			right = i - 1;
			while (left < right)
			{
				Swap(&s[left], &s[right]);
				++left;
				--right;
			}
			left = i + 1;
		}
	}
	right = len - 1;
	while (left < right)
	{
		Swap(&s[left], &s[right]);
		++left;
		--right;
	}
	return s;
}