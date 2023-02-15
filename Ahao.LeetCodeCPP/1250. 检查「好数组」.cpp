#include<vector>
#include <numeric>

using namespace std;

/*
1250. 检查「好数组」

给你一个正整数数组 nums，你需要从中任选一些子集，然后将子集中每一个数乘以一个 任意整数，并求出他们的和。

假如该和结果为 1，那么原数组就是一个「好数组」，则返回 True；否则请返回 False。
*/

class Solution {
public:
	bool isGoodArray(vector<int>& nums) {
		int divisor = nums[0];
		for (int num : nums) {
			divisor = gcd(divisor, num);
			if (divisor == 1) {
				break;
			}
		}
		return divisor == 1;
	}

	//求最大公约数
	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}

};
