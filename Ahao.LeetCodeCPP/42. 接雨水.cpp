using namespace std;
#include<vector>


/*
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
计算按此排列的柱子，下雨之后能接多少雨水。
*/
class Solution {
public:
	int trap(vector<int>& height) {
		int l = 0, r = height.size() - 1;
		int lmax = 0, rmax = 0, ans = 0;
		while (l < r) {
			lmax = max(lmax, height[l]);
			rmax = max(rmax, height[r]);
			if (lmax < rmax) {
				ans += lmax - height[l];
				l++;
			}
			else {
				ans += rmax - height[r];
				r--;
			}
		}
		return ans;
	}
};


/*
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/
class Solution {
public:
	int trap(vector<int>& height) {
		int l = 0, r = height.size() - 1;
		int lmax = 0, rmax = 0, ans = 0;
		while (l < r) {
			lmax = max(lmax, height[l]);
			rmax = max(rmax, height[r]);
			if (lmax < rmax) {
				ans += lmax - height[l];
				l++;
			}
			else {
				ans += rmax - height[r];
				r--;
			}
		}
		return ans;
	}
};