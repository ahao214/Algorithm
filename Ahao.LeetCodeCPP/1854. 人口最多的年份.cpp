#include<vector>

using namespace std;


/*
1854. 人口最多的年份
给你一个二维整数数组 logs ，其中每个 logs[i] = [birthi, deathi] 表示第 i 个人的出生和死亡年份。

年份 x 的 人口 定义为这一年期间活着的人的数目。第 i 个人被计入年份 x 的人口需要满足：x 在闭区间 [birthi, deathi - 1] 内。注意，人不应当计入他们死亡当年的人口中。

返回 人口最多 且 最早 的年份。
*/
class Solution {
public:
	int maximumPopulation(vector<vector<int>>& logs) {
		//res表示年份 cnt表示人数
		int res, cnt = 0;
		for (int i = 1950; i <= 2050; i++)
		{
			int s = 0;
			for (auto& log : logs)
			{
				if (i >= log[0] && i < log[1])
					s++;
			}
			if (s > cnt)
				res = i, cnt = s;
		}
		return res;
	}
};
