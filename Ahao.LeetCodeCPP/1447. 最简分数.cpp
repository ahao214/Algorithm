#include<vector>
#include<string>

using namespace std;


/*
1447. 最简分数
给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。
*/
class Solution {
public:
	//求最大公约数
	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}

	vector<string> simplifiedFractions(int n) {
		vector<string> res;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (gcd(i, j) == 1)
					res.push_back(to_string(j) + '/' + to_string(i));
			}
		}
		return res;
	}
};