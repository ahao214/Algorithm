#include<vector>
#include<string>

using namespace std;

/*
2609. 最长平衡子字符串

给你一个仅由 0 和 1 组成的二进制字符串 s 。

如果子字符串中 所有的 0 都在 1 之前 且其中 0 的数量等于 1 的数量，则认为 s 的这个子字符串是平衡子字符串。请注意，空子字符串也视作平衡子字符串。

返回  s 中最长的平衡子字符串长度。

子字符串是字符串中的一个连续字符序列。
*/


class Solution {
public:
	int findTheLongestBalancedSubstring(string s) {
		int res = 0, n = s.size();
		vector<int> count(2);
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				count[1]++;
				res = max(res, 2 * min(count[0], count[1]));
			}
			else if (i == 0 || s[i - 1] == '1') {
				count[0] = 1;
				count[1] = 0;
			}
			else {
				count[0]++;
			}
		}
		return res;
	}
};
