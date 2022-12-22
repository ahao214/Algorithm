#include<string>

using namespace std;

class Solution {
public:
	int magicalString(int n) {
		if (n < 4) {
			return 1;
		}
		string s(n, '0');
		s[0] = '1', s[1] = '2', s[2] = '2';
		int res = 1;
		int i = 2;
		int j = 3;
		while (j < n) {
			int size = s[i] - '0';
			int num = 3 - (s[j - 1] - '0');
			while (size > 0 && j < n) {
				s[j] = '0' + num;
				if (num == 1) {
					++res;
				}
				++j;
				--size;
			}
			++i;
		}
		return res;
	}
};



/*
481. 神奇字符串
神奇字符串 s 仅由 '1' 和 '2' 组成，并需要遵守下面的规则：

神奇字符串 s 的神奇之处在于，串联字符串中 '1' 和 '2' 的连续出现次数可以生成该字符串。
s 的前几个元素是 s = "1221121221221121122……" 。如果将 s 中连续的若干 1 和 2 进行分组，可以得到 "1 22 11 2 1 22 1 22 11 2 11 22 ......" 。每组中 1 或者 2 的出现次数分别是 "1 2 2 1 1 2 1 2 2 1 2 2 ......" 。上面的出现次数正是 s 自身。

给你一个整数 n ，返回在神奇字符串 s 的前 n 个数字中 1 的数目。
*/
class Solution {
public:
	int magicalString(int n) {
		string s = "122";
		for (int i = 2, k = 1; i < n; i++, k = 3 - k)
		{
			for (int j = 0; j < s[i] - '0'; j++)
				s += to_string(k);
		}
		int res = 0;
		for (int i = 0; i < n; i++)
			res += s[i] == '1';
		return res;
	}
};
