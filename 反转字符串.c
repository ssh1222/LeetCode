//��дһ���������������ǽ�������ַ�����ת������
//
//ʾ�� 1:
//
//���� : "hello"
//��� : "olleh"
//	 ʾ�� 2 :
//
// ���� : "A man, a plan, a canal: Panama"
//  ��� : "amanaP :lanac a ,nalp a ,nam A"

char* reverseString(char* s)
{
	int left = 0;
	int right = strlen(s) - 1;
	while (left < right)
	{
		char tmp = *(s + left);
		*(s + left) = *(s + right);
		*(s + right) = tmp;
		++left;
		--right;
	}
	return s;
}