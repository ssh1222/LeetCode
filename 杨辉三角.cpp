//����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�

class Solution {
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> arr;
		arr.resize(numRows);
		for (int i = 0; i < numRows; i++){
			arr[i].resize(i + 1);
			arr[i][0] = arr[i][i] = 1;
		}
		for (int i = 2; i < numRows; i++){
			for (int j = 1; j < i; j++){
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
		return arr;
	}
};