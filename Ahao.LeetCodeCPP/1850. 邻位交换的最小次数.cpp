#include<vector>
#include <algorithm>
#include<string>

using namespace std;


/*
1850. 邻位交换的最小次数
给你一个表示大整数的字符串 num ，和一个整数 k 。

如果某个整数是 num 中各位数字的一个 排列 且它的 值大于 num ，则称这个整数为 妙数 。可能存在很多妙数，但是只需要关注 值最小 的那些。

例如，num = "5489355142" ：
第 1 个最小妙数是 "5489355214"
第 2 个最小妙数是 "5489355241"
第 3 个最小妙数是 "5489355412"
第 4 个最小妙数是 "5489355421"
返回要得到第 k 个 最小妙数 需要对 num 执行的 相邻位数字交换的最小次数 。

测试用例是按存在第 k 个最小妙数而生成的。
*/
class Solution {
public:
	int getMinSwaps(string num, int k) {
		string b = num;
		while (k--) next_permutation(b.begin(), b.end());

		int n = num.size();
		vector<int> c(n);
		int cnt[10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			int x = num[i] - '0';
			cnt[x]++;
			int y = cnt[x];
			for (int j = 0; j < n; j++)
			{
				if (b[j] - '0' == x && --y == 0)
				{
					c[i] = j;
					break;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				if (c[i] > c[j])
					res++;
		}
		return res;
	}

};