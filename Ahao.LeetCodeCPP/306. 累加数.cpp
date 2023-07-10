#include<vector>
#include <string>

using namespace std;


/*
306. 累加数

累加数 是一个字符串，组成它的数字可以形成累加序列。

一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，序列中的每个后续数字必须是它之前两个数字之和。

给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。

说明：累加序列里的数，除数字 0 之外，不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
*/
class Solution {
public:
	string add(string x, string y)
	{
		vector<int> A, B, C;
		for (int i = x.size() - 1; i >= 0; i--) A.push_back(x[i] - '0');
		for (int i = y.size() - 1; i >= 0; i--) B.push_back(y[i] - '0');
		for (int i = 0, t = 0; i < A.size() || i < B.size() || t; i++)
		{
			if (i < A.size()) t += A[i];
			if (i < B.size()) t += B[i];
			C.push_back(t % 10);
			t /= 10;
		}
		string z;
		for (int i = C.size() - 1; i >= 0; i--)
			z += to_string(C[i]);
		return z;
	}

	bool isAdditiveNumber(string num) {
		for (int i = 0; i < num.size(); i++)
		{
			for (int j = i + 1; j + 1 < num.size(); j++)
			{
				int a = -1, b = i, c = j;
				while (true)
				{
					if (b - a > 1 && num[a + 1] == '0' || c - b > 1 && num[b + 1] == '0') break;//有前导零

					auto x = num.substr(a + 1, b - a), y = num.substr(b + 1, c - b);
					auto z = add(x, y);
					if (num.substr(c + 1, z.size()) != z) break; //下一个数不匹配
					a = b, b = c, c = c + z.size();
					if (c + 1 == num.size()) return true;
				}
			}
		}
		return false;
	}
};