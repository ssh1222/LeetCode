//����һ����������Сд��ĸ�Ϳո� ' ' ���ַ��������������һ�����ʵĳ��ȡ�
//
//������������һ�����ʣ��뷵�� 0 ��
//
//˵����һ��������ָ����ĸ��ɣ����������κοո���ַ�����
//
//ʾ�� :
//
//���� : "Hello World"
//��� : 5

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