#include<vector>
#include <deque>
#include <set>

using namespace std;


/*
918. 环形子数组的最大和

给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。

环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。

子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。
*/
class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		vector<int> s(n + n + 1, 0);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
		for (int i = n + 1; i <= 2 * n; i++) s[i] = s[i - 1] + nums[i - n - 1];

		multiset<int> sets;
		int res = INT_MIN;
		for (int i = 0; i <= n; i++) sets.insert(s[i]);
		for (int i = n + 1, j = 0; i <= n + n; i++, j++)
		{
			auto it = sets.find(s[j]);
			sets.erase(it);
			res = max(res, s[i] - *sets.begin());
			sets.insert(s[i]);
		}
		return res;
	}


	int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) nums.push_back(nums[i]);

		vector<int> sum(n * 2 + 1);
		for (int i = 1; i <= n * 2; i++) sum[i] = sum[i - 1] + nums[i - 1];

		int res = INT_MIN;
		deque<int> q;
		q.push_back(0);

		for (int i = 1; i <= n * 2; i++)
		{
			if (q.size() && i - n > q.front()) q.pop_front();
			if (q.size()) res = max(res, sum[i] - sum[q.front()]);
			while (q.size() && sum[q.back()] >= sum[i]) q.pop_back();
			q.push_back(i);
		}
		return res;
	}
};




class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		vector<int> leftMax(n);
		// 对坐标为 0 处的元素单独处理，避免考虑子数组为空的情况
		leftMax[0] = nums[0];
		int leftSum = nums[0];
		int pre = nums[0];
		int res = nums[0];
		for (int i = 1; i < n; i++) {
			pre = max(pre + nums[i], nums[i]);
			res = max(res, pre);
			leftSum += nums[i];
			leftMax[i] = max(leftMax[i - 1], leftSum);
		}

		// 从右到左枚举后缀，固定后缀，选择最大前缀
		int rightSum = 0;
		for (int i = n - 1; i > 0; i--) {
			rightSum += nums[i];
			res = max(res, rightSum + leftMax[i - 1]);
		}
		return res;
	}
};



