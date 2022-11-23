#include<vector>
#include <algorithm>

using namespace std;



/*
1498. ������������������Ŀ
����һ���������� nums ��һ������ target ��

����ͳ�Ʋ����� nums ������������СԪ�������Ԫ�ص� �� С�ڻ���� target �� �ǿ� �����е���Ŀ��

���ڴ𰸿��ܴܺ��뽫����� 10^9 + 7 ȡ��󷵻ء�
*/
class Solution {
public:
	int numSubseq(vector<int>& nums, int target) {
		int n = nums.size(), mod = 1e9 + 7;
		vector<int> p(n);
		p[0] = 1;
		for (int i = 1; i < n; i++)
			p[i] = p[i - 1] * 2 % mod;

		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0, j = n - 1; i < n; i++)
		{
			while (j >= i && nums[i] + nums[j] > target) j--;
			if (j >= i && nums[i] + nums[j] <= target)
			{
				res = (res + p[j - i]) % mod;
			}
		}

		return res;
	}
};