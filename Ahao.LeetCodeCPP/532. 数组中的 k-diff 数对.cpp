#include<vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


//¹şÏ£±í
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


//ÅÅĞò+Ë«Ö¸Õë
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
