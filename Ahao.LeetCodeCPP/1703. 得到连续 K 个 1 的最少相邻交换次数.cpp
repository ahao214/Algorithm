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


class Solution {
public:
	int minMoves(vector<int>& nums, int k) {
		vector<int> g;
		vector<int> preSum(1, 0);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				g.emplace_back(i - g.size());
				preSum.emplace_back(preSum.back() + g.back());
			}
		}
		int m = g.size(), res = INT_MAX;
		for (int i = 0; i <= m - k; i++) {
			int mid = i + k / 2;
			res = min(res, (1 - k % 2) * g[mid] + \
				(preSum[i + k] - preSum[mid + 1]) - \
				(preSum[mid] - preSum[i]));
		}
		return res;
	}
};
