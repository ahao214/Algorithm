#include<vector>
#include <algorithm>
#include <queue>

using namespace std;



/*
857. 雇佣 K 名工人的最低成本
有 n 名工人。 给定两个数组 quality 和 wage ，其中，quality[i]
表示第 i 名工人的工作质量，其最低期望工资为 wage[i] 。

现在我们想雇佣 k 名工人组成一个工资组。在雇佣 一组 k 名工人时，
我们必须按照下述规则向他们支付工资：

对工资组中的每名工人，应当按其工作质量与同组其他工人的工作质量的比例来
支付工资。
工资组中的每名工人至少应当得到他们的最低期望工资。
给定整数 k ，返回组成满足上述条件的付费群体所需的最小金额 。
在实际答案的 10-5 以内的答案将被接受。。
*/
class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
		int n = quality.size();
		vector<pair<double, int>> workers;
		for (int i = 0; i < n; i++)
			workers.push_back({ wage[i] * 1.0 / quality[i], quality[i] });
		sort(workers.begin(), workers.end());

		priority_queue<int> heap;
		double res = 1e9;
		int sum = 0;
		for (auto worker : workers)
		{
			heap.push(worker.second);
			sum += worker.second;
			if (heap.size() > k)
			{
				sum -= heap.top();
				heap.pop();
			}
			if (heap.size() == k) res = min(res, sum * worker.first);
		}
		return res;
	}
};