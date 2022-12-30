#include<vector>
#include <string>

using namespace std;


/*
1071. 字符串的最大公因子
对于字符串 S 和 T，只有在 S = T + ... + T（T 自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
*/
class Solution {
public:
	/*
	比较两个字符串的长度
	从长度长的字符串中减去长度短的字符串，在比较两个字符串的长度
	再次从长的里面减去短的，直到一个为空
	*/
	string gcdOfStrings(string str1, string str2) {
		if (str1.size() < str2.size())
		{
			return gcdOfStrings(str2, str1);
		}
		if (str2.empty())
			return str1;
		if (str1.substr(0, str2.size()) != str2)
			return "";
		return gcdOfStrings(str1.substr(str2.size()), str2);
	}
};