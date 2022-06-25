#include<vector>

using namespace std;



class Solution {
	/*
	70. 爬楼梯
	假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

	每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
	*/
public:
	/*
	Times:O(n)
	Space:O(n)
	动态规划
	*/
	int climbStairs(int n) {
		vector<int> f(n + 2);
		f[1] = 1, f[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};