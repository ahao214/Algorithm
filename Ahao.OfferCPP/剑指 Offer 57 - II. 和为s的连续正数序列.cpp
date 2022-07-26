#include<vector>

using namespace std;



/*
剑指 Offer 57 - II. 和为s的连续正数序列
*/
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> ans;
		if (target < 3) return ans;

		int left = 1, right = 2, curSum = 3;
		int mid = (target + 1) >> 1;
		while (left < mid)
		{
			if (curSum == target)
				FindCore(ans, left, right);
			while (curSum > target && left < mid)
			{
				curSum -= left;
				left++;
				if (curSum == target)
					FindCore(ans, left, right);
			}
			right++;
			curSum += right;
		}

		return ans;
	}

	void FindCore(vector<vector<int>>& ans, int left, int right)
	{
		vector<int> tmp;
		for (int i = left; i <= right; ++i)
		{
			tmp.push_back(i);
		}
		ans.push_back(tmp);
	}
};