#include<vector>
#include <algorithm>

using namespace std;


/*
493. ��ת��

����һ������ nums ����� i < j �� nums[i] > 2*nums[j] ���Ǿͽ� (i, j) ����һ����Ҫ��ת�ԡ�

����Ҫ���ظ��������е���Ҫ��ת�Ե�������
*/
class Solution {
	int res = 0;
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int> sorted = nums;
		helper(nums, sorted, 0, n - 1);
		return res;
	}

	void helper(vector<int>& nums, vector<int>& sorted, int a, int b)
	{
		if (a >= b) return;
		int mid = a + (b - a) / 2;
		helper(nums, sorted, a, mid);
		helper(nums, sorted, mid + 1, b);

		for (int j = mid + 1; j <= b; j++)
		{
			auto iter = upper_bound(sorted.begin() + a, sorted.begin() + mid + 1, 2 * (long)nums[j]);
			res += sorted.begin() + mid + 1 - iter;
		}
		sort(sorted.begin() + a, sorted.begin() + b + 1);
	}
};

