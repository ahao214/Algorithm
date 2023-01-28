#include<vector>

using namespace std;


/*
1664. 生成平衡数组的方案数

给你一个整数数组 nums 。你需要选择 恰好 一个下标（下标从 0 开始）并删除对应的元素。请注意剩下元素的下标可能会因为删除操作而发生改变。

比方说，如果 nums = [6,1,7,4,1] ，那么：

选择删除下标 1 ，剩下的数组为 nums = [6,7,4,1] 。
选择删除下标 2 ，剩下的数组为 nums = [6,1,4,1] 。
选择删除下标 4 ，剩下的数组为 nums = [6,1,7,4] 。
如果一个数组满足奇数下标元素的和与偶数下标元素的和相等，该数组就是一个 平衡数组 。

请你返回删除操作后，剩下的数组 nums 是 平衡数组 的 方案数 。
*/
class Solution {
public:
	/*
	先求出数组的总和sum
	奇数位之和：删除某个i值之后，奇数位的数字之和等于i为之前奇数位之和和i位之后偶数位之和
	偶数位之和：sum - arr[i] - 奇数位之和
	*/
	int waysToMakeFair(vector<int>& nums) {
		int n = nums.size();
		vector<int> s1(n + 1), s2(n + 1);
		for (int i = 1; i <= n; i++)
		{
			s1[i] = s1[i - 1], s2[i] = s2[i - 1];
			if (i % 2) s1[i] += nums[i - 1];
			else s2[i] += nums[i - 1];
		}

		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			//奇数位之和
			int odd = s1[i - 1] + s2[n] - s2[i];
			//偶数位之和
			int even = s2[i - 1] + s1[n] - s1[i];
			if (odd == even) res++;
		}
		return res;
	}
};



//动态规划
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd1 = 0, even1 = 0;
        int odd2 = 0, even2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) {
                odd2 += nums[i];
            }
            else {
                even2 += nums[i];
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) {
                odd2 -= nums[i];
            }
            else {
                even2 -= nums[i];
            }
            if (odd1 + even2 == odd2 + even1) {
                ++res;
            }
            if (i & 1) {
                odd1 += nums[i];
            }
            else {
                even1 += nums[i];
            }
        }
        return res;
    }
};
