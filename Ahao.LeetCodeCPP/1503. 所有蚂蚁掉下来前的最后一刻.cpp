#include<vector>

using namespace std;



/*
1503. 所有蚂蚁掉下来前的最后一刻
有一块木板，长度为 n 个 单位 。一些蚂蚁在木板上移动，每只蚂蚁都以 每秒一个单位 的速度移动。其中，一部分蚂蚁向 左 移动，其他蚂蚁向 右 移动。

当两只向 不同 方向移动的蚂蚁在某个点相遇时，它们会同时改变移动方向并继续移动。假设更改方向不会花费任何额外时间。

而当蚂蚁在某一时刻 t 到达木板的一端时，它立即从木板上掉下来。

给你一个整数 n 和两个整数数组 left 以及 right 。两个数组分别标识向左或者向右移动的蚂蚁在 t = 0 时的位置。请你返回最后一只蚂蚁从木板上掉下来的时刻。
*/
class Solution {
public:
	/*
	两只蚂蚁相碰的时候，想象成是两只蚂蚁互换了身份而已
	只需要计算向左走的蚂蚁最大需要多少时间以及向右走的蚂蚁最大需要多少时间，取两时间的最大值
	*/
	int getLastMoment(int n, vector<int>& left, vector<int>& right) {
		int res = 0;
		for (auto x : left) res = max(res, x);
		for (auto x : right) res = max(res, n - x);
		return res;
	}
};