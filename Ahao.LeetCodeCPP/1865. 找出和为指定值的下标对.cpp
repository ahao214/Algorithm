#include<vector>
#include<unordered_map>

using namespace std;


/*
1865. 找出和为指定值的下标对
给你两个整数数组 nums1 和 nums2 ，请你实现一个支持下述两类查询的数据结构：

累加 ，将一个正整数加到 nums2 中指定下标对应元素上。
计数 ，统计满足 nums1[i] + nums2[j] 等于指定值的下标对 (i, j) 数目（0 <= i < nums1.length 且 0 <= j < nums2.length）。
实现 FindSumPairs 类：

FindSumPairs(int[] nums1, int[] nums2) 使用整数数组 nums1 和 nums2 初始化 FindSumPairs 对象。
void add(int index, int val) 将 val 加到 nums2[index] 上，即，执行 nums2[index] += val 。
int count(int tot) 返回满足 nums1[i] + nums2[j] == tot 的下标对 (i, j) 数目。
*/
class Solution {
public:
	vector<int> a, b;
	unordered_map<int, int> cnt;

	FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
		a = nums1, b = nums2;
		for (auto x : b) cnt[x]++;
	}

	void add(int index, int val) {
		cnt[b[index]]--;
		b[index] += val;
		cnt[b[index]]++;
	}

	int count(int tot) {
		int res = 0;
		for (auto x : a)
			res += cnt[tot - x];
		return res;
	}

};
