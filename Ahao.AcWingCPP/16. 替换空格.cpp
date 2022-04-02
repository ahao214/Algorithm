using namespace std;
#include<string>;

#pragma region 16. 替换空格

/*
请实现一个函数，把字符串中的每个空格替换成"%20"。

数据范围
0≤ 输入字符串的长度 ≤1000。
注意输出字符串的长度可能大于 1000。

样例
输入："We are happy."

输出："We%20are%20happy."
*/

/*
从前往后枚举原字符串：

如果遇到空格，则在string类型的答案中添加 "%20"；
如果遇到其他字符，则直接将它添加在答案中；

时间复杂度分析
原字符串只会被遍历常数次，所以总时间复杂度是 O(n)O(n)。
*/

#pragma endregion

class Solution {
public:
	string replaceSpaces(string& str) {
		string res;
		for (auto& c : str)
		{
			if (c == ' ')
				res += "%20";
			else
				res += c;
		}
		return res;
	}
};