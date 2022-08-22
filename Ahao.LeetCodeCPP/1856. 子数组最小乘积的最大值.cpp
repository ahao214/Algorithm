#include<vector>

using namespace std;


/*
1856. ��������С�˻������ֵ
һ������� ��С�˻� ����Ϊ��������� ��Сֵ ���� ����� �� ��

�ȷ�˵������ [3,2,5] ����Сֵ�� 2������С�˻�Ϊ 2 * (3+2+5) = 2 * 10 = 20 ��
����һ������������ nums �����㷵�� nums ���� �ǿ������� ����С�˻� �� ���ֵ �����ڴ𰸿��ܴܺ����㷵�ش𰸶�  109 + 7 ȡ�� �Ľ����

��ע�⣬��С�˻������ֵ���ǵ���ȡ����� ֮ǰ �Ľ������Ŀ��֤��С�˻������ֵ�� ��ȡ�� ������¿����� 64 λ�з������� ���档

������ ����Ϊһ������� ���� ���֡�
*/

typedef long long LL;

const int N = 100010;

class Solution {
public:
	int h[N], left[N], right[N], q[N];

	LL s[N];
	int maxSumMinProduct(vector<int>& nums) {
		int n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			h[i] = nums[i - 1];
			s[i] = s[i - 1] + h[i];
		}
		h[0] = h[n + 1] = 0;
		int tt = 0;
		q[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			while (h[i] <= h[q[tt]]) tt--;
			left[i] = q[tt];
			q[++tt] = i;
		}

		tt = 0;
		q[0] = n + 1;
		for (int i = n; i; i--)
		{
			while (h[i] <= h[q[tt]]) tt--;
			right[i] = q[tt];
			q[++tt] = i;
		}

		LL res = 0;
		for (int i = 1; i <= n; i++)
			res = max(res, h[i] * (s[right[i] - 1] - s[left[i]]));
		return res % 1000000007;
	}
};
