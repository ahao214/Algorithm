using namespace std;
#include<string>
#include<vector>

class Solution {
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



/*
6. Z 字形变换
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，
比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
*/
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		string res;
		for (int i = 0; i < numRows; i++)
		{
			if (!i || i == numRows - 1)
			{
				for (int j = i; j < s.size(); j += 2 * (numRows - 1))
					res += s[j];
			}
			else
			{
				for (int j = i, k = 2 * (numRows - 1) - i; j < s.size() || k < s.size(); j += 2 * (numRows - 1), k += 2 * (numRows - 1))
				{
					if (j < s.size()) res += s[j];
					if (k < s.size()) res += s[k];
				}
			}
		}
		return res;
	}
};
