//����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
//
//ʾ�� 1:
//
//���� : "Let's take LeetCode contest"
//��� : "s'teL ekat edoCteeL tsetnoc"

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