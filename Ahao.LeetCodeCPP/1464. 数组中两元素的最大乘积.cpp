#include<vector>
#include<algorithm>

using namespace std;


/*
1464. 数组中两元素的最大乘积
*/
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return (nums.back() - 1) * (nums[nums.size() - 2] - 1);
	}
};

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int a = nums[0], b = nums[1];
		if (a < b) {
			swap(a, b);
		}
		for (int i = 2; i < nums.size(); i++) {
			if (nums[i] > a) {
				b = a;
				a = nums[i];
			}
			else if (nums[i] > b) {
				b = nums[i];
			}
		}
		return (a - 1) * (b - 1);
	}
};