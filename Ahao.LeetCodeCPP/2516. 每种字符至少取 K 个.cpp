#include<vector>
#include <string>

using namespace std;

/*
2516. 每种字符至少取 K 个
给你一个由字符 'a'、'b'、'c' 组成的字符串 s 和一个非负整数 k 。每分钟，你可以选择取走 s 最左侧 还是 最右侧 的那个字符。

你必须取走每种字符 至少 k 个，返回需要的 最少 分钟数；如果无法取到，则返回 -1 。
*/
class Solution {
public:
	int takeCharacters(string s, int k) {
		int aCount = 0;
		int bCount = 0;
		int cCount = 0;
		for (auto ch : s) {
			if (ch == 'a')
				aCount++;
			if (ch == 'b')
				bCount++;
			if (ch == 'c')
				cCount++;
		}

		if (aCount < k || bCount < k || cCount < k)
			return -1;

		aCount = aCount - k;
		bCount = bCount - k;
		cCount = cCount - k;

		int n = s.size();
		int j = 0;
		int a = 0, b = 0, c = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			while (a <= aCount && b <= bCount && c <= cCount) {
				res = max(res, j - i);
				if (j == n)
					break;
				if (s[j] == 'a') a++;
				if (s[j] == 'b') b++;
				if (s[j] == 'c') c++;
				j++;
			}
			if (s[i] == 'a') a--;
			if (s[i] == 'b') b--;
			if (s[i] == 'c') c--;
		}

		return n - res;
	}
};

