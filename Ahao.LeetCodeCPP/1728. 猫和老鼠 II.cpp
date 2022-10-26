#include<vector>
#include<string>

using namespace std;



/*
1728. è������ II
һֻè��һֻ��������һ������è���������Ϸ��

���������Ļ����趨��һ�� rows x cols �ķ��� grid ������ÿ�����ӿ�����һ��ǽ��һ��ذ塢һλ��ң�è�������󣩻���ʳ�

������ַ� 'C' ������è���� 'M' ���������󣩱�ʾ��
�ذ����ַ� '.' ��ʾ����ҿ���ͨ��������ӡ�
ǽ���ַ� '#' ��ʾ����Ҳ���ͨ��������ӡ�
ʳ�����ַ� 'F' ��ʾ����ҿ���ͨ��������ӡ�
�ַ� 'C' �� 'M' �� 'F' �� grid �ж�ֻ�����һ�Ρ�
è�����������¹����ƶ���

���� ���ƶ� ��Ȼ��������������ƶ���
ÿһ�β���ʱ��è����������������������ĸ�����֮һ�ĸ��ӣ����ǲ�������ǽҲ�������� grid ��
catJump �� mouseJump ��è������ֱ���һ���ܵ������Զ���룬����Ҳ������С��������ĳ��ȡ�
���ǿ���ͣ����ԭ�ء�
���������Ծ��è��λ�á�
��Ϸ�� 4 �ַ�ʽ�������

���è����������ͬ��λ�ã���ôè��ʤ��
���è�ȵ���ʳ���ôè��ʤ��
��������ȵ���ʳ���ô�����ʤ��
����������� 1000 �β������ڵ���ʳ���ôè��ʤ��
���� rows x cols �ľ��� grid ���������� catJump �� mouseJump ��˫������ȡ���Ų��ԣ���������ʤ����ô���㷵�� true �����򷵻� false ��
*/

int f[8][8][8][8][200];
class Solution {
public:
	int n, m, cj, mj;
	vector<string> g;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

	int dp(int cx, int cy, int mx, int my, int k)
	{
		if (k >= 200) return 0;
		auto& v = f[cx][cy][mx][my][k];
		if (v != -1) return v;

		if (k & 1)
		{
			//è
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= cj; j++)
				{
					int x = cx + dx[i] * j, y = cy + dy[i] * j;
					if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#') break;
					if (x == mx && y == my) return v = 0;
					if (g[x][y] == 'F') return v = 0;
					if (!dp(x, y, mx, my, k + 1)) return v = 0;
				}
			}
			return v = 1;
		}
		else
		{
			//����
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= mj; j++)
				{
					int x = mx + dx[i] * j, y = my + dy[i] * j;
					if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#') break;
					if (x == cx && y == cy) continue;
					if (g[x][y] == 'F') return v = 1;
					if (dp(cx, cy, x, y, k + 1)) return v = 1;
				}
			}
			return v = 0;
		}
	}

	bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
		g = grid;
		n = g.size(), m = g[0].size(), cj = catJump, mj = mouseJump;
		int cx, cy, mx, my;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (g[i][j] == 'C') cx = i, cy = j;
				else if (g[i][j] == 'M') mx = i, my = j;

		memset(f, -1, sizeof f);
		return dp(cx, cy, mx, my, 0);
	}
};


