//����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��
//
//
//
//ʾ�� 1��
//
//���룺"ab-cd"
//�����"dc-ba"
//ʾ�� 2��
//
//���룺"a-bC-dEf-ghIj"
//�����"j-Ih-gfE-dCba"
//ʾ�� 3��
//
//���룺"Test1ng-Leet=code-Q!"
//�����"Qedo1ct-eeLg=ntse-T!"

char* reverseOnlyLetters(char* S)
{
	for (int i = 0, j = strlen(S) - 1; i < j;){
		if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z')){
			if ((S[j] >= 'A' && S[j] <= 'Z') || (S[j] >= 'a' && S[j] <= 'z')){
				char t = S[i];
				S[i] = S[j];
				S[j] = t;
				i++;
				j--;
			}
			else j--;
		}
		else{
			i++;
			if ((S[j] > 'Z' && S[j] < 'a') || S[j] < 'A' || S[j] > 'z')
				j--;
		}
	}
	return S;
}