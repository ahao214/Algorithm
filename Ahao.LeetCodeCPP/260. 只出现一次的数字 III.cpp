#include<vector>

using namespace std;


/*
260. 只出现一次的数字 III
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。
找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
*/
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int s = 0;
		for (auto x : nums) {
			s ^= x;
		}
		int k = 0;
		while (!(s >> k & 1)) k++;

		int s2 = 0;
		for (auto x : nums) {
			if (x >> k & 1) {
				s2 ^= x;
			}
		}
		return vector<int>({ s2,s ^ s2 });
	}
};