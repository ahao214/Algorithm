#include<vector>
#include <queue>


using namespace std;


/*
2530. 执行 K 次操作后的最大分数

给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。你的 起始分数 为 0 。

在一步 操作 中：

选出一个满足 0 <= i < nums.length 的下标 i ，
将你的 分数 增加 nums[i] ，并且
将 nums[i] 替换为 ceil(nums[i] / 3) 。
返回在 恰好 执行 k 次操作后，你可能获得的最大分数。

向上取整函数 ceil(val) 的结果是大于或等于 val 的最小整数。
*/


class Solution {
public:
	long long maxKelements(vector<int>& nums, int k) {
		priority_queue<int> q(nums.begin(), nums.end());
		long long ans = 0;
		for (int _ = 0; _ < k; ++_) {
			int x = q.top();
			q.pop();
			ans += x;
			q.push((x + 2) / 3);
		}
		return ans;
	}
};

