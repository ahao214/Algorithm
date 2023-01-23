#include<vector>
#include <algorithm>

using namespace std;


/*
1029. 两地调度

公司计划面试 2n 人。给你一个数组 costs ，其中 costs[i] = [aCosti, bCosti] 。第 i 人飞往 a 市的费用为 aCosti ，飞往 b 市的费用为 bCosti 。

返回将每个人都飞到 a 、b 中某座城市的最低费用，要求每个城市都有 n 人抵达。
*/
class Solution {
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		sort(costs.begin(), costs.end(), [&](vector<int>& a, vector<int>& b) {
			return a[0] - a[1] < b[0] - b[1];
			});

		int n = costs.size() / 2;
		int res = 0;
		for (int i = 0; i < n; i++)
			res += costs[i][0];
		for (int i = n; i < n * 2; i++)
			res += costs[i][1];
		return res;
	}
};
