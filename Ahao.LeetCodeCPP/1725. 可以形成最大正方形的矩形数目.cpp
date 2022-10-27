#include<vector>

using namespace std;


/*
1725. 可以形成最大正方形的矩形数目
给你一个数组 rectangles ，其中 rectangles[i] = [li, wi] 表示第 i 个矩形的长度为 li 、宽度为 wi 。

如果存在 k 同时满足 k <= li 和 k <= wi ，就可以将第 i 个矩形切成边长为 k 的正方形。例如，矩形 [4,6] 可以切成边长最大为 4 的正方形。

设 maxLen 为可以从矩形数组 rectangles 切分得到的 最大正方形 的边长。

请你统计有多少个矩形能够切出边长为 maxLen 的正方形，并返回矩形 数目 。
*/
class Solution {
public:
	/*
	先求出rectangles可以组成矩形的最大的值
	然后在rectangles找出长和宽都大于等于最大值的个数
	*/
	int countGoodRectangles(vector<vector<int>>& rectangles) {
		int maxLen = 0;
		for (auto& t : rectangles)
			maxLen = max(maxLen, min(t[0], t[1]));
		int res = 0;
		for (auto& t : rectangles)
			if (t[0] >= maxLen && t[1] >= maxLen)
				res++;
		return res;
	}
};