#include<vector>

using namespace std;


/*
1776. 车队 II
在一条单车道上有 n 辆车，它们朝着同样的方向行驶。给你一个长度为 n 的数组 cars ，其中 cars[i] = [positioni, speedi] ，它表示：

positioni 是第 i 辆车和道路起点之间的距离（单位：米）。题目保证 positioni < positioni+1 。
speedi 是第 i 辆车的初始速度（单位：米/秒）。
简单起见，所有车子可以视为在数轴上移动的点。当两辆车占据同一个位置时，我们称它们相遇了。一旦两辆车相遇，它们会合并成一个车队，这个车队里的车有着同样的位置和相同的速度，速度为这个车队里 最慢 一辆车的速度。

请你返回一个数组 answer ，其中 answer[i] 是第 i 辆车与下一辆车相遇的时间（单位：秒），如果这辆车不会与下一辆车相遇，则 answer[i] 为 -1 。答案精度误差需在 10-5 以内。
*/
typedef pair<double, double> PDD;
#define x first
#define y second
class Solution {
public:

	double cross(double x1, double y1, double x2, double y2)
	{
		return x1 * y2 - x2 * y1;
	}

	double area(PDD a, PDD b, PDD c)
	{
		return cross(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
	}

	vector<double> getCollisionTimes(vector<vector<int>>& cars) {
		int n = cars.size();
		vector<PDD> stk(n + 1);
		vector<double> res(n);
		int top = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			auto& c = cars[i];
			PDD p(c[0], c[1]);
			while (top >= 2 && area(p, stk[top], stk[top - 1]) <= 0) top--;
			if (!top) res[i] = -1;
			else
			{
				auto& q = stk[top];
				if (p.y <= q.y) res[i] = -1;
				else res[i] = (q.x - p.x) / (p.y - q.y);
			}
			stk[++top] = p;
		}
		return res;
	}
};