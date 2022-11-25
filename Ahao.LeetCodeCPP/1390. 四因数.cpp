#include<vector>

using namespace std;


/*
1390. 四因数
给你一个整数数组 nums，请你返回该数组中恰有四个因数的这些整数的各因数之和。

如果数组中不存在满足题意的整数，则返回 0 。
*/
class Solution {
public:
	int sumFourDivisors(vector<int>& nums) {
		int res = 0;
		for (auto x : nums)
		{
			int sum = 0, cnt = 0;	//cnt 因数的个数
			for (int i = 1; i * i < x; i++)
			{
				if (x % i == 0)
				{
					sum += i, cnt++;
					//不是平方数的时候
					if (x / i != i) sum += x / i, cnt++;
				}
			}
			if (cnt == 4)
				res += sum;
		}
		return res;
	}
};