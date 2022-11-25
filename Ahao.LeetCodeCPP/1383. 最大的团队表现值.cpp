#include<vector>
#include <queue>

using namespace std;


/*
1383. 最大的团队表现值
公司有编号为 1 到 n 的 n 个工程师，给你两个数组 speed 和 efficiency ，其中 speed[i] 和 efficiency[i] 分别代表第 i 位工程师的速度和效率。请你返回由最多 k 个工程师组成的最大团队表现值 ，由于答案可能很大，请你返回结果对 10^9 + 7 取余后的结果。

团队表现值 的定义为：一个团队中「所有工程师速度的和」乘以他们「效率值中的最小值」。
*/
class Solution {
public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		//小根堆
		priority_queue<int, vector<int>, greater<int>> heap;

		vector<pair<int, int>> engs;
		for (int i = 0; i < n; i++)
			engs.push_back({ efficiency[i],speed[i] });
		sort(engs.begin(), engs.end());

		long long res = 0, sum = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			heap.push(engs[i].second);
			sum += engs[i].second;
			if (heap.size() > k)
			{
				sum -= heap.top();
				heap.pop();
			}
			res = max(res, sum * engs[i].first);
		}
		return res % 1000000007;
	}
};