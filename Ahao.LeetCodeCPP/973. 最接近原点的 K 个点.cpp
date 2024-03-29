#include<vector>
#include <algorithm>

using namespace std;


/*
973. 最接近原点的 K 个点

给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，并且是一个整数 k ，返回离原点 (0,0) 最近的 k 个点。

这里，平面上两点之间的距离是 欧几里德距离（ √(x1 - x2)2 + (y1 - y2)2 ）。

你可以按 任何顺序 返回答案。除了点坐标的顺序之外，答案 确保 是 唯一 的。
*/
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		nth_element(points.begin(), points.begin() + k - 1, points.end(), [](vector<int>& a, vector<int>& b) {
			return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
			});
		return vector<vector<int>>(points.begin(), points.begin() + k);
	}
};