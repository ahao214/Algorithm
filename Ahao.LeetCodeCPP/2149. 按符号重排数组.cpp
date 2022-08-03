#include<vector>

using namespace std;


/*
2149. 按符号重排数组
给你一个下标从 0 开始的整数数组 nums ，数组长度为 偶数 ，由数目相等的正整数和负整数组成。

你需要 重排 nums 中的元素，使修改后的数组满足下述条件：

任意 连续 的两个整数 符号相反
对于符号相同的所有整数，保留 它们在 nums 中的 顺序 。
重排后数组以正整数开头。
重排元素满足上述条件后，返回修改后的数组。
*/
class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		vector<int>a, b;
		for (auto x : nums)
		{
			if (x > 0) a.push_back(x);
			else b.push_back(x);
		}
		vector<int> res;
		for (int i = 0; i < a.size(); i++)
		{
			res.push_back(a[i]);
			res.push_back(b[i]);
		}
		return res;
	}
};