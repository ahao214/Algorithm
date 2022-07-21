#include<vector>

using namespace std;



/*
1608. 特殊数组的特征值
*/

class Solution {
public:
	//O(NlogN)
	int specialArray(vector<int>& nums) {
		int left = 1, right = nums.size();
		while (left < right)
		{
			int x = right - (right - left) / 2;
			int count = 0;
			for (auto a : nums)
			{
				if (a >= x)
					count++;
			}
			if (count >= x)
				left = x;
			else
				right = x - 1;
		}

		//判断是否有解
		int cnt = 0;
		for (auto a : nums)
		{
			if (a >= left) cnt++;
		}
		if (cnt == left)
			return left;
		else
			return -1;
	}

	//O(NlogN)
	int specialArray(vector<int>& nums) {
		int left = 1, right = nums.size();
		while (left <= right)
		{
			int x = right - (right - left) / 2;
			int count = 0;
			for (auto a : nums)
			{
				if (a >= x)
					count++;
			}
			if (count == x)
				return x;
			else if (count > x)
				left = x + 1;
			else
				right = x - 1;
		}

		return -1;
	}

	//O(N)
	int specialArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> freq(n + 1, 0);

		for (auto a : nums)
			freq[min(a, n)]++;
		int cnt = 0;
		for (int x = n; x >= 1; x--)
		{
			cnt += freq[x];
			if (cnt == x)
				return x;
		}
		return -1;
	}
};
