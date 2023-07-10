#include<vector>
#include <algorithm>
#include <numeric>

using namespace std;


/*
1979. 找出数组的最大公约数

给你一个整数数组 nums ，返回数组中最大数和最小数的 最大公约数 。

两个数的 最大公约数 是能够被两个数整除的最大正整数。
*/

class Solution {
public:
	int findGCD(vector<int>& nums) {
		int mx = *max_element(nums.begin(), nums.end());
		int mn = *min_element(nums.begin(), nums.end());
		return gcd(mx, mn);
	}

	//求最大公约数
	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}
};
