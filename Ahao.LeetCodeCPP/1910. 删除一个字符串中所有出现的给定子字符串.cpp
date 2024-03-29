#include<vector>
#include<string>

using namespace std;



/*
1910. 删除一个字符串中所有出现的给定子字符串
给你两个字符串 s 和 part ，请你对 s 反复执行以下操作直到 所有 子字符串 part 都被删除：

找到 s 中 最左边 的子字符串 part ，并将它从 s 中删除。
请你返回从 s 中删除所有 part 子字符串以后得到的剩余字符串。

一个 子字符串 是一个字符串中连续的字符序列。
*/
class Solution {
public:
	string removeOccurrences(string s, string part) {
		while (true)
		{
			int k = s.find(part);
			if (k == -1) break;
			s = s.substr(0, k) + s.substr(k + part.size());
		}
		return s;
	}
};

