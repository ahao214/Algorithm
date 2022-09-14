#include<vector>

using namespace std;


/*
1793. ���������������
����һ���������� nums ���±�� 0 ��ʼ����һ������ k ��

һ�������� (i, j) �� ���� ����Ϊ min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1) ��һ�� �� ������������˵��±���Ҫ���� i <= k <= j ��

���㷵�� �� ������������� ���� ��
*/
class Solution {
public:
	int maximumScore(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> h(n + 2, -1), left(n + 2), right(n + 2), stk(n + 2);
		for (int i = 1; i <= n; i++)
			h[i] = nums[i - 1];
		int tt = 0;
		stk[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			while (h[stk[tt]] >= h[i]) tt--;
			left[i] = stk[tt];
			stk[++tt] = i;
		}
		tt = 0, stk[0] = n + 1;
		for (int i = n; i; i--)
		{
			while (h[stk[tt]] >= h[i]) tt--;
			right[i] = stk[tt];
			stk[++tt] = i;
		}
		k++;
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			if (left[i] < k && right[i] > k)
				res = max(res, (right[i] - left[i] - 1) * h[i]);
		}
		return res;
	}

};