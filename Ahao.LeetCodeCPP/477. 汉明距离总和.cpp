#include<vector>

using namespace std;


/*
477. 汉明距离总和

两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
给你一个整数数组 nums，请你计算并返回nums中任意两个数之间汉明距离的总和 。
*/
class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i <= 30; i++) {
			int ones = 0;
			for (auto x : nums) {
				if (x >> i & 1)
					ones++;
			}
			res += ones * (nums.size() - ones);
		}
		return res;
	}
};



class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i <= 30; i++) {
			int ones = 0;
			for (auto x : nums) {
				if (x >> i & 1)
					ones++;
			}
			res += ones * (nums.size() - ones);
		}
		return res;
	}
};