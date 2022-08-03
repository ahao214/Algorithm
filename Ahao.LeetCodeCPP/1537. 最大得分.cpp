#include<vector>

using namespace std;


/*
1537. 最大得分
*/
class Solution {
public:
	int maxSum(vector<int>& nums1, vector<int>& nums2) {
		int i = 0, j = 0;
		long long x = 0, y = 0;
		int m = nums1.size();
		int n = nums2.size();
		long long MOD = 1e9 + 7;

		while (i < m || j < n)
		{
			if (i == m)
			{
				y += nums2[j];
				j++;
			}
			else if (j == n)
			{
				x += nums1[i];
				i++;
			}
			else if (nums1[i] < nums2[j])
			{
				x += nums1[i];
				i++;
			}
			else if (nums1[i] > nums2[j])
			{
				y += nums2[j];
				j++;
			}
			else if (nums1[i] == nums2[j])
			{
				x = max(x + nums1[i], y + nums2[j]);
				y = x;
				i++;
				j++;
			}
		}
		return max(x, y) % MOD;
	}
};