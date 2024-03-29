#include<vector>

using namespace std;

//方法一：模拟
class Solution {
public:
	int numSpecial(vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		vector<int> rowsSum(m);
		vector<int> colsSum(n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				rowsSum[i] += mat[i][j];
				colsSum[j] += mat[i][j];
			}
		}
		int res = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 1 && rowsSum[i] == 1 && colsSum[j] == 1) {
					res++;
				}
			}
		}
		return res;
	}
};





//方法二：列的标记值
class Solution {
public:
	int numSpecial(vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		for (int i = 0; i < m; i++) {
			int cnt1 = 0;
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 1) {
					cnt1++;
				}
			}
			if (i == 0) {
				cnt1--;
			}
			if (cnt1 > 0) {
				for (int j = 0; j < n; j++) {
					if (mat[i][j] == 1) {
						mat[0][j] += cnt1;
					}
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (mat[0][i] == 1) {
				sum++;
			}
		}
		return sum;
	}
};
