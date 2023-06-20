#include<vector>

using namespace std;


/*
478. 在圆内随机生成点
*/
class Solution {
public:
	double r, x, y;

	Solution(double radius, double x_center, double y_center) {
		r = radius, x = x_center, y = y_center;
	}

	vector<double> randPoint() {
		while (true)
		{
			double a = (double)rand() / RAND_MAX * 2 - 1, b = (double)rand() / RAND_MAX * 2 - 1;
			if (a * a + b * b > 1) continue;
			return { x + a * r,y + b * r };
		}
	}
};