#include<vector>
#include <unordered_set>
#include <algorithm>

using namespace std;



/*
350. 两个数组的交集 II

给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
*/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
		unordered_multiset<int> hash;
		for (auto x : nums1) hash.insert(x);
		vector<int> res;
		for (auto x : nums2)
		{
			if (hash.count(x))
			{
				res.push_back(x);
				auto it = hash.find(x);
				hash.erase(it);
			}
		}
		return res;
	}
};



class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		vector<int> res;
		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] < nums2[j])
				++i;
			else if (nums1[i] > nums2[j])
				++j;
			else
			{
				res.push_back(nums1[i]);
				++i;
				++j;
			}
		}
		return res;
	}
};
