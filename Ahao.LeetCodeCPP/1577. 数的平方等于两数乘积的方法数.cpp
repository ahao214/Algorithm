#include<vector>
#include <unordered_map>

using namespace std;


/*
1577. 数的平方等于两数乘积的方法数
给你两个整数数组 nums1 和 nums2 ，请你返回根据以下规则形成的三元组的数目（类型 1 和类型 2 ）：

类型 1：三元组 (i, j, k) ，如果 nums1[i]^2 == nums2[j] * nums2[k] 其中 0 <= i < nums1.length 且 0 <= j < k < nums2.length
类型 2：三元组 (i, j, k) ，如果 nums2[i]^2 == nums1[j] * nums1[k] 其中 0 <= i < nums2.length 且 0 <= j < k < nums1.length
*/
class Solution {
public:
	int work(vector<int>& a, vector<int>& b)
	{
		int res = 0;
		//哈希表
		unordered_map<long long, int> hash;
		for (int x : a) hash[(long long)x * x]++;
		for (int j = 0; j < b.size(); j++)
		{
			for (int k = j + 1; k < b.size(); k++)
				res += hash[(long long)b[j] * b[k]];
		}
		return res;
	}

	int numTriplets(vector<int>& nums1, vector<int>& nums2) {
		return work(nums1, nums2) + work(nums2, nums1);
	}
};
