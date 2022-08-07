#include<vector>

using namespace std;




/*
1905. ͳ���ӵ���
�������� m x n �Ķ����ƾ��� grid1 �� grid2 ������ֻ���� 0 ����ʾˮ�򣩺� 1 ����ʾ½�أ���һ�� ���� ���� �ĸ����� ��ˮƽ������ֱ�������ڵ� 1 ��ɵ������κξ��������������Ϊˮ��

��� grid2 ��һ�����죬�� grid1 ��һ������ ��ȫ ������Ҳ����˵ grid2 �иõ����ÿһ�����Ӷ��� grid1 ��ͬһ��������ȫ��������ô���ǳ� grid2 �е��������Ϊ �ӵ��� ��

���㷵�� grid2 �� �ӵ��� �� ��Ŀ ��
*/
class Solution {
public:
	int n, m;
	vector<vector<int>> g1, g2;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

	bool dfs(int x, int y)
	{
		g2[x][y] = 0;
		bool res = true;
		if (!g1[x][y]) res = false;
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b < m && g2[a][b])
			{
				if (!dfs(a, b)) res = false;
			}
		}
		return res;
	}

	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		g1 = grid1, g2 = grid2;
		n = g1.size(), m = g1[0].size();
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (g2[i][j])
					if (dfs(i, j))res++;
			}
		}
		return res;
	}
};
