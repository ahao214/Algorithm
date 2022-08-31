#include<vector>
#include<algorithm>

using namespace std;




/*
1838. 最高频元素的频数
元素的 频数 是该元素在一个数组中出现的次数。

给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。

执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。
*/
class Solution {
public:
	int maxFrequency(vector<int>& nums, int k) {
		typedef long long LL;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<LL> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
		int res = 0;
		for (int i = 1, j = 1; i <= n; i++)
		{
			while ((i - j + 1ll) * nums[i - 1] - (s[i] - s[j - 1]) > k)
				j++;
			res = max(res, i - j + 1);
		}
		return res;
	}
};
