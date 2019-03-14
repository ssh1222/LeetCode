//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
//
//
//
//示例 1：
//
//输入："ab-cd"
//输出："dc-ba"
//示例 2：
//
//输入："a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"
//示例 3：
//
//输入："Test1ng-Leet=code-Q!"
//输出："Qedo1ct-eeLg=ntse-T!"

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