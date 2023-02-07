#include<vector>

using namespace std;


/*
877. ʯ����Ϸ

Alice �� Bob �ü���ʯ��������Ϸ��һ����ż����ʯ�ӣ��ų�һ�У�ÿ�Ѷ��� �� ������ʯ�ӣ���ĿΪ piles[i] ��

��Ϸ��˭���е�ʯ�����������ʤ����ʯ�ӵ� ���� �� ���� ������û��ƽ�֡�

Alice �� Bob �������У�Alice �ȿ�ʼ �� ÿ�غϣ���Ҵ��е� ��ʼ �� ���� ��ȡ������ʯͷ�� �������һֱ������û�и����ʯ�Ӷ�Ϊֹ����ʱ���� ʯ����� ����� ��ʤ ��

���� Alice �� Bob �����ӳ����ˮƽ���� Alice Ӯ�ñ���ʱ���� true ���� Bob Ӯ�ñ���ʱ���� false ��
*/
class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		int n = piles.size();
		vector<vector<int>> f(n, vector<int>(n));
		for (int len = 1; len <= n; len++)
		{
			for (int i = 0; i + len - 1 < n; i++)
			{
				int j = i + len - 1;
				if (len == 1)
					f[i][j] = piles[i];
				else
				{
					f[i][j] = max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1]);
				}
			}
		}
		return f[0][n - 1];
	}
};