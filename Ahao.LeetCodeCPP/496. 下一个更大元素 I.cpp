#include<vector>
#include <stack>
#include <unordered_map>

using namespace std;



/*
496. 下一个更大元素 I
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
*/
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> stk;
		unordered_map<int, int> hash;
		for (int j = nums2.size() - 1; j >= 0; j--)
		{
			while (stk.size() && stk.top() <= nums2[j])
				stk.pop();
			hash[nums2[j]] = stk.size() ? stk.top() : -1;
			stk.push(nums2[j]);
		}
		vector<int> res;
		for (auto x : nums1)
			res.push_back(hash[x]);
		return res;
	}
};