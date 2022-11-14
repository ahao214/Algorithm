#include<vector>
#include <algorithm>

using namespace std;


/*
2164. 对奇偶下标分别排序
题目难度Easy
给你一个下标从 0 开始的整数数组 nums 。根据下述规则重排 nums 中的值：

按 非递增 顺序排列 nums 奇数下标 上的所有值。
举个例子，如果排序前 nums = [4,1,2,3] ，对奇数下标的值排序后变为 [4,3,2,1] 。奇数下标 1 和 3 的值按照非递增顺序重排。
按 非递减 顺序排列 nums 偶数下标 上的所有值。
举个例子，如果排序前 nums = [4,1,2,3] ，对偶数下标的值排序后变为 [2,1,4,3] 。偶数下标 0 和 2 的值按照非递减顺序重排。
返回重排 nums 的值之后形成的数组。
*/
class Solution {
public:
	vector<int> sortEvenOdd(vector<int>& a) {
		vector<int>x, y;
		for (int i = 0; i < a.size(); i++)
		{
			if (i % 2 == 0) x.push_back(a[i]);
			else y.push_back(a[i]);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end(), greater<int>());

		vector<int>res;
		for (int i = 0; i < y.size(); i++)
		{
			res.push_back(x[i]);
			res.push_back(y[i]);
		}
		if (a.size() % 2 == 1) res.push_back(x.back());
		return res;
	}
};

class Solution {
public:
	vector<int> sortEvenOdd(vector<int>& nums) {
		vector<int> ans;
		vector<int> num1;
		vector<int> num2;
		int N = nums.size();
		for (int i = 0; i < N; i++) {
			if ((i & 1) == 0) {
				num1.push_back(nums[i]);
			}
			else {
				nums.push_back(nums[i]);
			}
		}
		sort(num1.begin(), num1.end());
		sort(num2.begin(), num2.end());
		reverse(num2.begin(), num2.end());
		for (int i = 0; i < N; i++) {
			if ((i & 1) == 0) {
				ans.push_back(num1[i / 2]);
			}
			else {
				ans.push_back(num2[i / 2]);
			}
		}
		return ans;
	}
};