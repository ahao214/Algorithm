#include<vector>

using namespace std;


/*
1749. ����������͵ľ���ֵ�����ֵ
����һ���������� nums ��һ�������� [numsl, numsl+1, ..., numsr-1, numsr] �� �͵ľ���ֵ Ϊ abs(numsl + numsl+1 + ... + numsr-1 + numsr) ��

�����ҳ� nums �� �͵ľ���ֵ �������������飨����Ϊ�գ��������ظ� ���ֵ ��

abs(x) �������£�

��� x �Ǹ���������ô abs(x) = -x ��
��� x �ǷǸ���������ô abs(x) = x ��
*/
class Solution {
public:
	/*ǰ׺��*/
	int maxAbsoluteSum(vector<int>& nums) {
		int n = nums.size();
		vector<int> s(n + 1);
		for (int i = 1; i < n; i++)
			s[i] = s[i - 1] + nums[i - 1];
		int res = 0;
		int minv = 0, maxv = 0;
		for (int i = 1; i <= n; i++)
		{
			res = max(res, abs(s[i] - minv));
			res = max(res, abs(s[i] - maxv));
			minv = min(minv, s[i]);
			maxv = max(maxv, s[i]);
		}
		return res;
	}
};
