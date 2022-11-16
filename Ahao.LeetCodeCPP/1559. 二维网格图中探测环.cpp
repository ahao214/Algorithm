#include<vector>

using namespace std;


/*
1559. ��ά����ͼ��̽�⻷
����һ����ά�ַ��������� grid ����СΪ m x n ������Ҫ��� grid ���Ƿ���� ��ֵͬ �γɵĻ���

һ������һ����ʼ�ͽ�����ͬһ�����ӵĳ��� ���ڵ��� 4 ��·��������һ�������ĸ��ӣ�������ƶ������ϡ��¡������ĸ��������ڵĸ���֮һ�������ƶ���ǰ���������������� ��ͬ��ֵ ��

ͬʱ����Ҳ���ܻص���һ���ƶ�ʱ���ڵĸ��ӡ��ȷ�˵����  (1, 1) -> (1, 2) -> (1, 1) �ǲ��Ϸ��ģ���Ϊ�� (1, 2) �ƶ��� (1, 1) �ص�����һ���ƶ�ʱ�ĸ��ӡ�

��� grid ������ֵͬ�γɵĻ������㷵�� true �����򷵻� false ��
*/
class Solution {
public:
	vector<vector<char>> g;
	vector<vector<bool>> st;

	bool containsCycle(vector<vector<char>>& grid) {
		g = grid;
		st = vector<vector<bool>>(g.size(), vector<bool>(g[0].size()));
		for (int i = 0; i < g.size(); i++)
		{
			for (int j = 0; j < g[0].size(); j++)
			{
				if (!st[i][j] && dfs(i, j, -1))
					return true;
			}
		}
		return false;
	}

	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
	bool dfs(int x, int y, int p)
	{
		st[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			if (i != p)
			{
				int a = x + dx[i], b = y + dy[i];
				if (a >= 0 && a < g.size() && b >= 0 && b < g[0].size() && g[x][y] == g[a][b])
				{
					if (st[a][b])return true;
					if (dfs(a, b, i ^ 1)) return true;
				}
			}
		}
		return false;
	}
};

