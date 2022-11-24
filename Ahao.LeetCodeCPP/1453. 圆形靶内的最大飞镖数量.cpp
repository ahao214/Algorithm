#include<vector>

using namespace std;


/*
1453. 圆形靶内的最大飞镖数量
墙壁上挂着一个圆形的飞镖靶。现在请你蒙着眼睛向靶上投掷飞镖。

投掷到墙上的飞镖用二维平面上的点坐标数组表示。飞镖靶的半径为 r 。

请返回能够落在任意半径为 r 的圆形靶内或靶上的最大飞镖数。
*/
class Solution {
public:
	const double eps = 1e-8;
	double f(double x)
	{
		return x * x;
	}

	vector<vector<double>> get_centers(vector<int> a, vector<int> b, double r)
	{
		double x0 = a[0], y0 = a[1];
		double x1 = b[0], y1 = b[1];
		double cx = (x0 + x1) / 2, cy = (y0 + y1) / 2;
		double d = sqrt(f(x0 - x1) + f(y0 - y1));
		d /= 2;

		vector<vector<double>> res;
		if (d > r) return res;
		double h = sqrt(r * r - d * d);
		d *= 2;
		double vx = (x1 - x0) / d, vy = (y1 - y0) / d;
		double hx = -vy, hy = vx;
		res.push_back({ cx + h * hx,cy + h * hy });
		res.push_back({ cx - h * hx,cy - h * hy });
		return res;
	}

	int numPoints(vector<vector<int>>& darts, int r) {
		int n = darts.size();
		int res = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				auto centers = get_centers(darts[i], darts[j], r);
				for (auto center : centers)
				{
					int cnt = 0;
					double cx = center[0], cy = center[1];
					for (int k = 0; k < n; k++)
					{
						double dx = darts[k][0] - cx, dy = darts[k][1] - cy;
						if (dx * dx + dy * dy <= r * r + eps)
							cnt++;
					}
					res = max(res, cnt);
				}
			}
		}
		return res;
	}
};
