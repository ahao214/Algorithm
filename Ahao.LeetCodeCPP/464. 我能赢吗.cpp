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
