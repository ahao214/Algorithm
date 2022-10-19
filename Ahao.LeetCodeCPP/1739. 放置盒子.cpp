#include<vector>

using namespace std;


/*
1739. 放置盒子
有一个立方体房间，其长度、宽度和高度都等于 n 个单位。请你在房间里放置 n 个盒子，每个盒子都是一个单位边长的立方体。放置规则如下：

你可以把盒子放在地板上的任何地方。
如果盒子 x 需要放置在盒子 y 的顶部，那么盒子 y 竖直的四个侧面都 必须 与另一个盒子或墙相邻。
给你一个整数 n ，返回接触地面的盒子的 最少 可能数量。
*/
class Solution {
public:
	int minimumBoxes(int n) {
		int sum = 0, k = 1;
		while (sum + k * (k + 1) / 2 <= n)
		{
			sum += k * (k + 1) / 2;
			k++;
		}

		int res = k * (k - 1) / 2;
		k = 1;
		while (sum < n)
		{
			sum += k;
			k++;
			res++;
		}
		return res;
	}
};
