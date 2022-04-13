using namespace std;
#include<vector>;

class Solution {
	/*
	11. 盛最多水的容器
	给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

	说明：你不能倾斜容器。
	*/
public:
	int maxArea(vector<int>& height) {
		//左右指针,谁小移动谁
		int res = 0;
		int l = 0, r = height.size() - 1;
		while (l < r) {
			res = max(res, min(height[l], height[r]) * (r - l));
			if (height[l] < height[r]) {
				l++;
			}
			else {
				r--;
			}
		}
		return res;
	}
};