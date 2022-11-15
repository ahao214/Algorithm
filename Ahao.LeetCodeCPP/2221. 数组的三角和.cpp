#include<vector>

using namespace std;


/*
2221. ��������Ǻ�

����һ���±�� 0 ��ʼ���������� nums ������ nums[i] �� 0 �� 9 ֮�䣨���߶���������һ�����֡�

nums �� ���Ǻ� ��ִ�����²����Ժ����ʣ��Ԫ�ص�ֵ��

nums ��ʼ���� n ��Ԫ�ء���� n == 1 ����ֹ ���������򣬴��� һ���µ��±�� 0 ��ʼ�ĳ���Ϊ n - 1 ���������� newNums ��
�������� 0 <= i < n - 1 ���±� i ��newNums[i] ��ֵ Ϊ (nums[i] + nums[i+1]) % 10 ��% ��ʾȡ�����㡣
�� newNums �滻 ���� nums ��
�Ӳ��� 1 ��ʼ �ظ� �������̡�
���㷵�� nums �����Ǻ͡�
*/
using ll = long long;
class Solution {
public:
	int triangularSum(vector<int>& nums) {
		int n = nums.size() - 1;
		ll comb[1000][1000];
		for (int i = 0; i <= n; i++) {
			comb[i][i] = comb[i][0] = 1;
			if (i == 0)
				continue;
			for (int j = 1; j < i; ++j) {
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
				comb[i][j] %= 10;
			}
		}
		ll res = 0;
		for (int i = 0; i <= n; i++) {
			res += nums[i] * comb[n][i] % 10;
		}
		return res % 10;
	}
};