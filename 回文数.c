//�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
//
//ʾ�� 1:
//
//���� : 121
//��� : true
//	 ʾ�� 2 :
//
// ���� : -121
//  ��� : false
//   ���� : �������Ҷ�, Ϊ - 121 �� ���������, Ϊ 121 - �����������һ����������
//		ʾ�� 3 :
//
//	���� : 10
//	 ��� : false
//	  ���� : ���������, Ϊ 01 �����������һ����������

bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}
	char array[20] = { 0 };
	sprintf(array, "%d", x);
	int len = strlen(array);
	int i = 0;
	while (i < len)
	{
		if (array[i] == array[len - 1])
		{
			++i;
			--len;
		}
		else
		{
			return false;
		}
	}
	return true;
}