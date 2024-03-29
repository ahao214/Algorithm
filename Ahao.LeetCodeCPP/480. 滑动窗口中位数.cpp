#include<vector>

using namespace std;



/*
480. 滑动窗口中位数
*/
class Solution {
public:
	int len;
	multiset<int> left, right;
	double get_medium()
	{
		if (len % 2) return *right.begin();
		return ((double)*left.rbegin() + *right.begin()) / 2;
	}
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		len = k;
		for (int i = 0; i < len; i++)
			right.insert(nums[i]);
		for (int i = 0; i < len / 2; i++)
		{
			left.insert(*right.begin());
			right.erase(right.begin());
		}
		vector<double> res;
		res.push_back(get_medium());
		for (int i = len; i < nums.size(); i++)
		{
			int x = nums[i], y = nums[i - len];
			if (x >= *right.begin()) right.insert(x);
			else left.insert(x);

			if (y >= *right.begin()) right.erase(right.find(y));
			else left.erase(left.find(y));

			while (left.size() > right.size())
			{
				right.insert(*left.rbegin());
				left.erase(left.find(*left.rbegin()));
			}
			while (right.size() > left.size() + 1)
			{
				left.insert(*right.begin());
				right.erase(right.begin());
			}
			res.push_back(get_medium());
		}
		return res;
	}
};