//ʵ�� strStr() ������
//
//����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ��(��0��ʼ)����������ڣ��򷵻� - 1��
//
//ʾ�� 1:
//
//���� : haystack = "hello", needle = "ll"
//��� : 2
//	 ʾ�� 2 :
//
// ���� : haystack = "aaaaa", needle = "bba"
//  ��� : -1
//   ˵�� :
//
//	  �� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣
//
//	  ���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե� strstr() �Լ� Java�� indexOf() ���������

int strStr(char* haystack, char* needle)
{
	int len1 = strlen(haystack), len2 = strlen(needle), i, j;
	if (len2 == 0){
		return 0;
	}
	for (i = 0; i <= len1 - len2; i++){
		int t = i;
		for (j = 0; j<len2; j++, t++){
			if (haystack[t] != needle[j]){
				break;
			}
		}
		if (j == len2){
			return i;
		}
	}
	return -1;
}