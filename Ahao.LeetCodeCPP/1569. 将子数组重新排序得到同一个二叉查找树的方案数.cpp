#include<vector>

using namespace std;


/*
1569. ����������������õ�ͬһ������������ķ�����
����һ������ nums ��ʾ 1 �� n ��һ�����С����ǰ���Ԫ���� nums �е�˳�����β���һ����ʼΪ�յĶ����������BST��������ͳ�ƽ� nums ���������ͳ���������������ķ����������ź�õ��Ķ���������� nums ԭ������˳��õ��Ķ����������ͬ��

�ȷ�˵������ nums = [2,1,3]�����ǵõ�һ�� 2 Ϊ����1 Ϊ���ӣ�3 Ϊ�Һ��ӵ��������� [2,3,1] Ҳ�ܵõ���ͬ�� BST���� [3,2,1] ��õ�һ�ò�ͬ�� BST ��

���㷵������ nums ����ԭ���� nums �õ���ͬ����������ķ�������

���ڴ𰸿��ܻ�ܴ��뽫����� 10^9 + 7 ȡ������
*/
typedef long long LL;
class Solution {
public:
	vector<vector<int>> C;
	const int MOD = 1e9 + 7;

	int numOfWays(vector<int>& nums) {
		int n = nums.size();
		C = vector<vector<int>>(n + 1, vector<int>(n + 1));
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (!j) C[i][j] = 1;
				else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
			}
		}
		return (f(nums) + MOD - 1) % MOD;
	}

	int f(vector<int> nums)
	{
		if (nums.empty())
			return 1;
		int n = nums.size();
		int k = nums[0];
		vector<int> left, right;
		for (auto x : nums)
		{
			if (x < k) left.push_back(x);
			else if (x > k) right.push_back(x - k);
		}
		return (LL)C[n - 1][k - 1] * f(left) % MOD * f(right) % MOD;
	}
};