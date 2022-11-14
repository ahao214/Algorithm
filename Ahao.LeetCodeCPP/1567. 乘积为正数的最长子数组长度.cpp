#include<vector>

using namespace std;


/*
1567. �˻�Ϊ������������鳤��
����һ���������� nums ����������˻�Ϊ�������������ĳ��ȡ�

һ�����������������ԭ������������߸��������������ɵ����顣

���㷵�س˻�Ϊ������������鳤�ȡ�
*/
class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int n = nums.size();
		vector<int> f(n), g(n);
		if (nums[0] > 0) f[0] = 1;
		else if (nums[0] < 0) g[0] = 1;

		int res = f[0];
		for (int i = 1; i < n; i++)
		{
			if (nums[i] > 0)
			{
				f[i] = f[i - 1] + 1;
				if (g[i - 1]) g[i] = g[i - 1] + 1;
			}
			else if (nums[i] < 0) {
				if (g[i - 1]) f[i] = g[i - 1] + 1;
				g[i] = f[i - 1] + 1;
			}
			res = max(res, f[i]);
		}

		return res;
	}
};
