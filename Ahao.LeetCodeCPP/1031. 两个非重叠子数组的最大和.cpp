#include<vector>

using namespace std;



/*
1031. �������ص������������

�����Ǹ��������� A �������������ص�����������������Ԫ�ص����ͣ�������ĳ��ȷֱ�Ϊ L �� M����������Ҫ������ǣ���Ϊ L ����������Գ����ڳ�Ϊ M ��������֮ǰ��֮�󡣣�

����ʽ�Ͽ����������� V���� V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) ��������������֮һ��

0 <= i < i + L - 1 < j < j + M - 1 < A.length, ��
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
*/

class Solution {
public:
	int work(vector<int>& nums, int a, int b)
	{
		int n = nums.size();
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++)
			s[i] = s[i - 1] + nums[i - 1];
		int res = 0;
		for (int i = a + b, maxa = 0; i <= n; i++)
		{
			maxa = max(maxa, s[i - b] - s[i - b - a]);
			res = max(res, s[i] - s[i - b] + maxa);
		}
		return res;
	}

	int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
		return max(work(nums, firstLen, secondLen), work(nums, secondLen, firstLen));
	}
};