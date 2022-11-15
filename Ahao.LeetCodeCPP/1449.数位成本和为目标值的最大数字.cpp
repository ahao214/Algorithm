#include<vector>
#include<string>

using namespace std;



/*
1449. ��λ�ɱ���ΪĿ��ֵ���������
����һ���������� cost ��һ������ target �����㷵���������¹�����Եõ��� ��� ������

����ǰ������һ����λ��i + 1���ĳɱ�Ϊ cost[i] ��cost �����±�� 0 ��ʼ����
�ܳɱ�����ǡ�õ��� target ��
��ӵ���λ��û������ 0 ��
���ڴ𰸿��ܻ�ܴ��������ַ�����ʽ���ء�

�����������Ҫ���޷��õ��κ����������㷵�� "0" ��
*/
class Solution {
	string dp[5001];
public:
	string largestNumber(vector<int>& cost, int target) {
		cost.insert(cost.begin(), 0);

		for (int c = 1; c <= target; c++)
		{
			dp[c] = "#";
			for (int i = 1; i <= 9; i++)
			{
				if (c < cost[i] || dp[c - cost[i]] == "#") continue;
				string candidate = dp[c - cost[i]] + to_string(i);
				if (candidate.size() > dp[c].size() || candidate.size() == dp[c].size() && candidate > dp[c])
					dp[c] = candidate;
			}
		}
		if (dp[target] == "#")
			return "0";
		else
			return dp[target];
	}
};




class Solution {
public:
	/*
	1��λ�����
	2��λ����ͬ,�ֵ������
	*/
	string largestNumber(vector<int>& cost, int target) {
		vector<vector<int>> f(10, vector<int>(target + 1));

		for (int i = 1; i <= target; i++) f[0][i] = -1e8;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 0; j <= target; j++)
			{
				f[i][j] = f[i - 1][j];
				if (j >= cost[i - 1])
					f[i][j] = max(f[i][j], f[i][j - cost[i - 1]] + 1);
			}
		}
		if (f[9][target] < 1) return "0";
		string res;
		for (int i = 9, j = target; i; i--)
		{
			while (j >= cost[i - 1] && f[i][j] == f[i][j - cost[i - 1]] + 1);
			{
				res += to_string(i);
				j -= cost[i - 1];
			}
		}
		return res;
	}
};


