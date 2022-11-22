#include<vector>
#include <string>
#include <queue>

using namespace std;


/*
1505. 最多 K 次交换相邻数位后得到的最小整数
给你一个字符串 num 和一个整数 k 。其中，num 表示一个很大的整数，字符串中的每个字符依次对应整数上的各个 数位 。

你可以交换这个整数相邻数位的数字 最多 k 次。

请你返回你能得到的最小整数，并以字符串形式返回。
*/
class Solution {
public:
	/*
	让第一位数字最小，第二位次小，第三位次次小	把整数中最小的数字尽量放到最前面，有相同的数字的时候，距离左边较近的数字，先进行交换，交换的次数要小于等于K

	记录数字0到9出现的所有位置

	例如：
	1、剩余的数中是否有0，找距离左边最近的0
	2、把0放到第一位，交换次数不能大于K
	*/

	int n;
	vector<int> tr;
	int lowbit(int x)
	{
		return x & -x;
	}

	void add(int x, int v)
	{
		for (int i = x; i <= n; i += lowbit(i))
			tr[i] += v;
	}

	int getSum(int x)
	{
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}

	string minInteger(string num, int k) {
		n = num.size();
		tr.resize(n + 1);
		num = ' ' + num;
		queue<int> q[10];
		for (int i = 1; i <= n; i++)
			q[num[i] - '0'].push(i);
		string res;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (q[j].size())
				{
					int t = q[j].front();
					int pos = t + getSum(t);
					if (pos - i <= k)
					{
						k -= pos - i;
						res += to_string(j);
						q[j].pop();
						add(1, 1), add(t, -1);
						break;
					}
				}
			}
		}
		return res;
	}
};
