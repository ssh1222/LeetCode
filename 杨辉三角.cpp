//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

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