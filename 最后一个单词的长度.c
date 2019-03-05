//给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
//
//如果不存在最后一个单词，请返回 0 。
//
//说明：一个单词是指由字母组成，但不包含任何空格的字符串。
//
//示例 :
//
//输入 : "Hello World"
//输出 : 5

int lengthOfLastWord(char* s)
{
	int count = 0;
	while (*s == ' '){
		s++;
	}
	char *s1 = s;
	while (*s != '\0'){
		if (*s != ' '){
			s1 = s;
		}
		while (*s++ != ' '){
			if (*s == '\0'){
				break;
			}
		}
	}
	s = s1;
	while (*s != ' '){
		if (*s == '\0'){
			break;
		}
		s++;
	}
	if (*s == '\0'){
		return strlen(s1);
	}
	s = s1;
	while (*s != ' '){
		s++;
	}
	while (*s == ' '){
		s++;
		count++;
	}
	return strlen(s1) - count;
}