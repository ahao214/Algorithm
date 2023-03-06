#include<vector>

using namespace std;


/*
765. 情侣牵手

n 对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手。

人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的 ID。情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n-2, 2n-1)。

返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起。 每次交换可选择任意两人，让他们站起来交换座位。
*/
class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x)
			p[x] = find(p[x]);
		return p[x];
	}
	int minSwapsCouples(vector<int>& row) {
		int n = row.size() / 2;
		for (int i = 0; i < n; i++)
			p.push_back(i);
		int cnt = n;
		for (int i = 0; i < n * 2; i += 2)
		{
			int a = row[i] / 2, b = row[i + 1] / 2;
			if (find(a) != find(b))
			{
				p[find(a)] = find(b);
				cnt--;
			}
		}
		return n - cnt;
	}
};