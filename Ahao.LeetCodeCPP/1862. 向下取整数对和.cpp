#include<vector>

using namespace std;



/*
1862. ����ȡ�����Ժ�
����һ���������� nums �����㷵�������±�� 0 <= i, j < nums.length �� floor(nums[i] / nums[j]) ���֮�͡����ڴ𰸿��ܻ�ܴ����㷵�ش𰸶�109 + 7 ȡ�� �Ľ����

���� floor() �����������ֵ��������֡�
*/

typedef long long LL;
const int N = 100010, MOD = 1e9 + 7;
int s[N];

class Solution {
public:
	int sumOfFlooredPairs(vector<int>& nums) {
		memset(s, 0, sizeof s);
		for (auto x : nums) s[x]++;
		for (int i = 1; i < N; i++) s[i] += s[i - 1];
		int res = 0;
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j * i < N; j++)
			{
				int left = j * i, right = min(N - 1, (j + 1) * i - 1);
				int sum = (LL)(s[right] - s[left - 1]) * j % MOD;
				res = (res + (LL)sum * (s[i] - s[i - 1])) % MOD;
			}
		}
		return res;
	}
};