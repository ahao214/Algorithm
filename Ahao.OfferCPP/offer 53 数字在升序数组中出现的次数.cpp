#include<vector>


using namespace std;


/*
offer 53 数字在升序数组中出现的次数
*/
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		return helper(data, k) - helper(data, k - 1);
	}

	int helper(vector<int>& data, int k)
	{
		int i = 0, j = data.size() - 1;
		while (i <= j)
		{
			int mid = (i + j) >> 1;
			if (data[mid] > k) j = mid - 1;
			else i = mid + 1;
		}
		return i;
	}
};

