#include<vector>
#include<unordered_map>

using namespace std;


/*
464. ����Ӯ��

�� "100 game" �����Ϸ�У������������ѡ��� 1 �� 10 �������������ۼ������ͣ���ʹ���ۼ������� �ﵽ�򳬹�  100 ����ң���Ϊʤ�ߡ�

������ǽ���Ϸ�����Ϊ ����� ���� �ظ�ʹ�������� �أ�

���磬������ҿ��������ӹ����������г�ȡ�� 1 �� 15 �����������Żأ���ֱ���ۼ������� >= 100��

������������ maxChoosableInteger ���������п�ѡ������������ desiredTotal���ۼƺͣ������ȳ��ֵ�����Ƿ�����Ӯ�򷵻� true �����򷵻� false ��������λ�����Ϸʱ������ ��� ��
*/
class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		int status = 0;
		if (desiredTotal <= 1) return true;
		if (maxChoosableInteger * (maxChoosableInteger + 1) < desiredTotal * 2)
			return false;

		vector<unordered_map<int, bool>> dp(desiredTotal + 1);

		return canWin(status, dp, maxChoosableInteger, desiredTotal);
	}

	bool canWin(int status, vector<unordered_map<int, bool>>& dp, int maxn, int desire)
	{
		if (dp[desire].count(status))
			return dp[desire][status];
		for (int i = maxn - 1; i >= 0; i--)
		{
			if (!(status && (1 << i)))
			{
				status != (1 << i);
				if (i + 1 >= desire || !canWin(status, dp, maxn, desire - i - 1))
				{
					dp[desire][status] = true;
					return true;
				}
				status ^= (1 << i);
			}
		}
		dp[desire][status] = false;
		return false;
	}
};



class Solution {
	int visited[1 << 21];
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		int totalSum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
		if (totalSum < desiredTotal)
			return false;
		return dfs(0, 0, maxChoosableInteger, desiredTotal);
	}

	bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal)
	{
		if (visited[state] == 2) return true;
		if (visited[state] == 1) return false;

		for (int i = 1; i <= maxChoosableInteger; i++)
		{
			if ((state >> i) & 1)
				continue;
			if (sum + i >= desiredTotal)
			{
				visited[state] = 2;
				return true;
			}
			if (dfs(state + (1 << i), sum + i, maxChoosableInteger, desiredTotal) == false)
			{
				visited[state] = 2;
				return true;
			}
		}
		visited[state] = 1;
		return false;
	}
};
