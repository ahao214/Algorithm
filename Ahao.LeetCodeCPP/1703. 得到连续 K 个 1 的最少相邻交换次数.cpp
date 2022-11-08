#include<vector>

using namespace std;


/*
1703. �õ����� K �� 1 ���������ڽ�������
����һ���������� nums ��һ������ k �� nums ������ 0 �� 1 ��ÿһ���ƶ��������ѡ�� ���� �������ֲ������ǽ�����

���㷵��ʹ nums �а��� k �� ���� 1 �� ���� ����������
*/
class Solution {
public:
	int minMoves(vector<int>& nums, int k) {
		vector<int> a;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i])
				a.push_back(i - a.size());
		}
		int n = a.size();
		typedef long long LL;
		vector<LL> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
		LL res = 1e8;
		for (int i = k; i <= n; i++)
		{
			int le = i - k + 1, ri = i;
			int mid = (le + ri) / 2;
			LL x = a[mid - 1];
			LL left = x * (mid - le) - (s[mid - 1] - s[le - 1]);
			LL right = (s[ri] - s[mid]) - x * (ri - mid);
			res = min(res, left + right);
		}
		return res;
	}
};