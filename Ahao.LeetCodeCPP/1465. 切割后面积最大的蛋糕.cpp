#include<vector>
#include <algorithm>

using namespace std;


/*
1465. 切割后面积最大的蛋糕

矩形蛋糕的高度为 h 且宽度为 w，给你两个整数数组 horizontalCuts 和 verticalCuts，其中 horizontalCuts[i] 是从矩形蛋糕顶部到第  i 个水平切口的距离，类似地， verticalCuts[j] 是从矩形蛋糕的左侧到第 j 个竖直切口的距离。

请你按数组 horizontalCuts 和 verticalCuts 中提供的水平和竖直位置切割后，请你找出 面积最大 的那份蛋糕，并返回其 面积 。由于答案可能是一个很大的数字，因此需要将结果对 10^9 + 7 取余后返回。
*/
class Solution {
public:
	//找到竖方向的最大值和横方向的最大值
	//两数相乘
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		//将边界加入到数组里面
		horizontalCuts.push_back(0), horizontalCuts.push_back(h);
		verticalCuts.push_back(0), verticalCuts.push_back(w);

		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());

		int x = 0, y = 0;
		for (int i = 1; i < horizontalCuts.size(); i++)
			x = max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
		for (int j = 1; j < verticalCuts.size(); j++)
			y = max(y, verticalCuts[j] - verticalCuts[j - 1]);

		return (long long)x * y % 1000000007;
	}
};


class Solution {
public:
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		int mod = 1e9 + 7;
		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());
		auto calMax = [](vector<int>& arr, int boardr) -> int {
			int res = 0, pre = 0;
			for (int i : arr) {
				res = max(i - pre, res);
				pre = i;
			}
			return max(res, boardr - pre);
		};
		return (long long)calMax(horizontalCuts, h) * calMax(verticalCuts, w) % mod;
	}
};

