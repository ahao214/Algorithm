#include<vector>
#include <numeric>

using namespace std;



/*
2197. 替换数组中的非互质数
*/
class Solution {
public:
	vector<int> replaceNonCoprimes(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			int x = nums[i];
			while (!res.empty() && gcd(res.back(), x) > 1)
			{
				x = lcm(res.back(), x);
				res.pop_back();
			}
			res.push_back(x);
		}
		return res;
	}

	long long lcm(long long a, long long b)
	{
		return a * b / (long long)gcd(a, b);
	}

	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
};

