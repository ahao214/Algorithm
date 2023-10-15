#include<vector>

using namespace std;


/*
137. 只出现一次的数字 II

给你一个整数数组 nums ，除某个元素仅出现一次外，
其余每个元素都恰出现三次
请你找出并返回那个只出现了一次的元素。
*/
class Solution {
public:
	/*
	状态机：
	初始：0 0
	1个1  1 0
	2个1  0 1
	3个1  1 0
	*/
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0;
		for (auto x : nums) {
			ones = (ones ^ x) & ~twos;
			twos = (twos ^ x) & ~ones;
		}
		return ones;
	}

	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int bit = 0; bit < 32; bit++) {
			int count = 0;
			for (int i = 0; i < nums.size(); i++) {
				count += (nums[i] >> bit) & 1;
			}
			ans += (count % 3) << bit;
		}
		return ans;
	}
};





class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < 32; i++)
		{
			int cnt = 0;
			for (auto& num : nums)
			{
				cnt += (num >> i) & 1;
			}
			if (cnt % 3)
				res |= (1 << i);
		}
		return res;
	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int a = 0, b = 0;
		for (int num : nums) {
			b = ~a & (b ^ num);
			a = ~b & (a ^ num);
		}
		return b;
	}
};



class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int a = 0, b = 0;
		for (int num : nums) {
			tie(a, b) = pair{ (~a & b & num) | (a & ~b & ~num), ~a & (b ^ num) };
		}
		return b;
	}
};
