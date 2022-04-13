using namespace std;
#include<string>
#include<vector>

class Solution {
	/*
	6. Z 字形变换
	将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
	*/
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		vector<string> rows(numRows);
		//方向变量
		bool down = false;
		for (int i = 0, row = 0; i < s.length(); i++) {
			rows[row] += s[i];
			if (row == 0 || row == numRows - 1)
				down = !down;
			row += down ? 1 : -1;
		}
		string res = "";
		for (int i = 0; i < numRows; i++) {
			res += rows[i];
		}
		return res;
	}
};