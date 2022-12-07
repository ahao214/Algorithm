#include<vector>

using namespace std;


/*
1775. ͨ�����ٲ�������ʹ����ĺ����
�����������ȿ��ܲ��ȵ��������� nums1 �� nums2 �����������е�����ֵ���� 1 �� 6 ֮�䣨���� 1 �� 6����

ÿ�β����У������ѡ�� ���� �����е�����һ��������������� 1 �� 6 ֮�� ���� ��ֵ������ 1 �� 6����

���㷵��ʹ nums1 ���������ĺ��� nums2 ���������ĺ���ȵ����ٲ�������������޷�ʹ��������ĺ���ȣ��뷵�� -1 ��
*/
class Solution {
public:
	int work(vector<int>& h, int s)
	{
		int sum = 0;
		for (int i = 1; i <= 6; i++)
			sum += i * h[i];

		if (sum > s)
		{
			int x = sum - s, res = 0;
			for (int i = 6; i > 1; i--)
			{
				int t = i - 1;
				if (h[i] * t >= x) return res + (x + t - 1) / t;
				res += h[i];
				x -= h[i] * t;
			}
			return res;
		}
		else {
			int x = s - sum, res = 0;
			for (int i = 1; i < 6; i++)
			{
				int t = 6 - i;
				if (h[i] * t >= x) return res + (x + t - 1) / t;
				res += h[i];
				x -= h[i] * t;
			}
			return res;
		}
	}

	int minOperations(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		if (n > m) return minOperations(nums2, nums1);

		if (m > n * 6) return -1;

		vector<int> h1(7), h2(7);
		for (auto x : nums1) h1[x]++;
		for (auto x : nums2) h2[x]++;
		int res = 1e9;
		for (int i = m; i <= 6 * n; i++)
			res = min(res, work(h1, i) + work(h2, i));
		return res;
	}
};


class Solution {
public:
	int help(vector<int>& h1, vector<int>& h2, int diff) {
		vector<int> h(7, 0);
		for (int i = 1; i < 7; ++i) {
			h[6 - i] += h1[i];
			h[i - 1] += h2[i];
		}
		int res = 0;
		for (int i = 5; i && diff > 0; --i) {
			int t = min((diff + i - 1) / i, h[i]);
			res += t;
			diff -= t * i;
		}
		return res;
	}

	int minOperations(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		if (6 * n < m || 6 * m < n) {
			return -1;
		}
		vector<int> cnt1(7, 0), cnt2(7, 0);
		int diff = 0;
		for (auto& i : nums1) {
			++cnt1[i];
			diff += i;
		}
		for (auto& i : nums2) {
			++cnt2[i];
			diff -= i;
		}
		if (!diff) {
			return 0;
		}
		if (diff > 0) {
			return help(cnt2, cnt1, diff);
		}
		return help(cnt1, cnt2, -diff);
	}
};

