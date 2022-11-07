#include<vector>

using namespace std;


/*
1712. ������ֳ�����������ķ�����
���ǳ�һ���ָ���������ķ����� �õ� ���������㣺

���鱻�ֳ����� �ǿ� ���������飬�������ҷֱ�����Ϊ left �� mid �� right ��
left ��Ԫ�غ�С�ڵ��� mid ��Ԫ�غͣ�mid ��Ԫ�غ�С�ڵ��� right ��Ԫ�غ͡�
����һ�� �Ǹ� �������� nums �����㷵�� �õ� �ָ� nums ������Ŀ�����ڴ𰸿��ܻ�ܴ����㽫����� 109 + 7 ȡ��󷵻ء�
*/
class Solution {
public:
	int waysToSplit(vector<int>& nums) {
		int n = nums.size(), mod = 1e9 + 7;
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
		int res = 0;
		for (int i = 3, j = 2, k = 2; i <= n; i++)
		{
			while (s[n] - s[i - 1] < s[i - 1] - s[j - 1]) j++;
			while (k + 1 < i && s[i - 1] - s[k] >= s[k]) k++;
			if (j <= k && s[n] - s[i - 1] >= s[i - 1] - s[j - 1] && s[i - 1] - s[k - 1] >= s[k - 1])
				res = (res + k - j + 1) % mod;
		}
		return res;
	}
};
