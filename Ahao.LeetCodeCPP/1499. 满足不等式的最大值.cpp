#include<vector>
#include <deque>

using namespace std;


/*
1499. 满足不等式的最大值
给你一个数组 points 和一个整数 k 。数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序。也就是说 points[i] = [xi, yi] ，并且在 1 <= i < j <= points.length 的前提下， xi < xj 总成立。

请你找出 yi + yj + |xi - xj| 的 最大值，其中 |xi - xj| <= k 且 1 <= i < j <= points.length。

题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。
*/
class Solution {
public:
	/*
	yi + yj + |xi - xj| = yi + yj + xj - xi =(yi - xi) + (yj + xj)
		滑动窗口求最值
	*/
	int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
		deque<int> q;	//单调队列
		int res = INT_MIN;

		for (int i = 0; i < points.size(); i++)
		{
			int x = points[i][0], y = points[i][1];
			while (q.size() && x - points[q.front()][0] > k) q.pop_front();
			if (q.size())
			{
				int t = q.front();
				res = max(res, x + y + points[t][1] - points[t][0]);
			}
			while (q.size() && points[q.back()][1] - points[q.back()][0] <= y - x)
				q.pop_back();
			q.push_back(i);
		}
		return res;
	}
};

