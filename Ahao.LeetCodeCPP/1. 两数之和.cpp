using namespace std;
#include<string>;
#include<vector>;
#include <unordered_map>

class Solution {
public:
	/// <summary>
	/// 暴力方法
	/// </summary>
	/// <param name="nums"></param>
	/// <param name="target"></param>
	/// <returns></returns>
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[i] + nums[j] == target) {
					return { i,j };
				}
			}
		}
		return {};
	}
};



class Solution {
	/*
	1. 两数之和
	给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
	你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
	你可以按任意顺序返回答案。
	*/
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//定义哈希表
		unordered_map<int, int> record;
		for (int i = 0; i < nums.size(); ++i) {
			int num = target - nums[i];
			if (record.find(num) != record.end()) {
				return { record[num],i };
			}
			record[nums[i]] = i;
		}
		return { -1, -1 };
	}
};