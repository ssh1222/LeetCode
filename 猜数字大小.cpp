//����������һ����������Ϸ�� ��Ϸ�������£�
//�Ҵ� 1 �� n ѡ��һ�����֡� ����Ҫ����ѡ�����ĸ����֡�
//ÿ����´��ˣ��һ��������������Ǵ��˻���С�ˡ�
//�����һ��Ԥ�ȶ���õĽӿ� guess(int num)�����᷵�� 3 �����ܵĽ���� - 1��1 �� 0����
//
//- 1 : �ҵ����ֱȽ�С
//1 : �ҵ����ֱȽϴ�
//0 : ��ϲ����¶��ˣ�
//ʾ�� :
//
//���� : n = 10, pick = 6
//��� : 6
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n)
	{
		int min = 1;
		int max = n;
		int mid = min;
		while (min <= max){
			mid = min + (max - min) / 2;
			if (guess(mid) == -1){
				max = mid - 1;
			}
			else if (guess(mid) == 1){
				min = mid + 1;
			}
			else {
				return mid;
			}
		}
		return 0;
	}
};