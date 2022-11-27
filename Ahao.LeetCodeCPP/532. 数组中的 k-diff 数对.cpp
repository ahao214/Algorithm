#include<vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


//哈希表
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		unordered_set<int> visited;
		unordered_set<int> res;
		for (int num : nums) {
			if (visited.count(num - k)) {
				res.emplace(num - k);
			}
			if (visited.count(num + k)) {
				res.emplace(num);
			}
			visited.emplace(num);
		}
		return res.size();
	}
};


//排序+双指针
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), y = 0, res = 0;
		for (int x = 0; x < n; x++) {
			if (x == 0 || nums[x] != nums[x - 1]) {
				while (y < n && (nums[y] < nums[x] + k || y <= x)) {
					y++;
				}
				if (y < n && nums[y] == nums[x] + k) {
					res++;
				}
			}
		}
		return res;
	}
};




/*
532. 数组中的 k-diff 数对
给定一个整数数组和一个整数 k，你需要在数组里找到 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。

这里将 k-diff 数对定义为一个整数对 (nums[i], nums[j])，并满足下述全部条件：

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
注意，|val| 表示 val 的绝对值。
*/
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		int size = nums.size();
		int left = 0, right = 1, res = 0;
		sort(nums.begin(), nums.end());
		while (left < size && right < size)
		{
			if (left == right || (nums[right] - nums[left]) < k)
			{
				right++;
			}
			else if (nums[right] - nums[left] > k)
			{
				left++;
			}
			else
			{
				res++;
				left++;
				while (left < size && nums[left] == nums[left - 1])
				{
					left++;
				}
			}
		}
		return res;
	}
};
