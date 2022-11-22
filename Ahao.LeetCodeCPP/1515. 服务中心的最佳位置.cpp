#include<vector>

using namespace std;


/*
1515. 服务中心的最佳位置
一家快递公司希望在新城市建立新的服务中心。公司统计了该城市所有客户在二维地图上的坐标，并希望能够以此为依据为新的服务中心选址：使服务中心 到所有客户的欧几里得距离的总和最小 。

给你一个数组 positions ，其中 positions[i] = [xi, yi] 表示第 i 个客户在二维地图上的位置，返回到所有客户的 欧几里得距离的最小总和 。

换句话说，请你为服务中心选址，该位置的坐标 [xcentre, ycentre] 需要使下面的公式取到最小值：

与真实值误差在 10-5之内的答案将被视作正确答案。
*/
class Solution {
public:
	vector<vector<int>> points;
	double getSum(double x, double y)
	{
		double sum = 0;
		for (auto& p : points)
		{
			double a = p[0], b = p[1];
			sum += sqrt((x - a) * (x - a) + (y - b) * (y - b));
		}
		return sum;
	}

	double calc(double x)
	{
		double l = 0, r = 100;
		while (r - l > 1e-7)
		{
			double y1 = l + (r - l) / 3, y2 = l + (r - l) / 3 * 2;
			if (getSum(x, y1) >= getSum(x, y2)) l = y1;
			else r = y2;
		}
		return getSum(x, r);
	}

	double getMinDistSum(vector<vector<int>>& positions) {
		points = positions;
		double l = 0, r = 100;
		while (r - l > 1e-7)
		{
			double x1 = l + (r - l) / 3, x2 = l + (r - l) / 3 * 2;
			if (calc(x1) >= calc(x2)) l = x1;
			else r = x2;
		}
		return calc(r);
	}
};