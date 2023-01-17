#include<vector>

using namespace std;


/*
1219. �ƽ��

��Ҫ����һ����󣬵��ʿ���ѧ���Ѿ�̽������������е���Դ�ֲ������ô�СΪ m * n ������ grid �����˱�ע��ÿ����Ԫ���е������ͱ�ʾ��һ��Ԫ���еĻƽ�����������õ�Ԫ���ǿյģ���ô���� 0��

Ϊ��ʹ������󻯣�����Ҫ�����¹��������ɻƽ�

ÿ���󹤽���һ����Ԫ���ͻ��ռ��õ�Ԫ���е����лƽ�
��ÿ�ο��Դӵ�ǰλ�������������ĸ������ߡ�
ÿ����Ԫ��ֻ�ܱ����ɣ����룩һ�Ρ�
���ÿ��ɣ����룩�ƽ���ĿΪ 0 �ĵ�Ԫ��
�󹤿��Դ������� ����һ�� �лƽ�ĵ�Ԫ�����������ֹͣ��
*/
class Solution {
public:
	int ans = 0;
	void f(vector<vector<int>>& grid, int x, int y, int num) {
		num += grid[x][y];
		ans = max(ans, num);
		const int dirs[4][2] = {
			{0,1},{0,-1},{-1,0},{1,0}
		};
		int m = grid.size(), n = grid[0].size(), tmp = grid[x][y];
		grid[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dirs[i][0], ny = y + dirs[i][1];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || !grid[nx][ny])
				continue;
			f(grid, nx, ny, num);
		}
		grid[x][y] = tmp;
	}

	int getMaximumGold(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j]) {
					f(grid, i, j, 0);
				}
			}
		}
		return ans;
	}
};
