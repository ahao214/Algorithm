#include<vector>
#include<unordered_map>

using namespace std;


/*
1726. 同积元组
给你一个由 不同 正整数组成的数组 nums ，请你返回满足 a * b = c * d 的元组 (a, b, c, d) 的数量。其中 a、b、c 和 d 都是 nums 中的元素，且 a != b != c != d 。
*/
class Solution {
public:
	int tupleSameProduct(vector<int>& nums) {
		int n = nums.size();
		//hash用来记录每种乘积的个数
		unordered_map<int, int> hash;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				hash[nums[i] * nums[j]]++;
			}
		}
		int res = 0;
		//p表示乘积 k表示个数
		for (auto& [p, k] : hash)
		{
			res += k * (k - 1) / 2 * 8;
		}
		return res;
	}
};
