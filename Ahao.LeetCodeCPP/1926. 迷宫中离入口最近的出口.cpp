#include<vector>
#include<queue>

using namespace std;


/*
1926. �Թ������������ĳ���
����һ�� m x n ���Թ����� maze ���±�� 0 ��ʼ�����������пո��ӣ��� '.' ��ʾ����ǽ���� '+' ��ʾ����ͬʱ�����Թ������ entrance ���� entrance = [entrancerow, entrancecol] ��ʾ��һ��ʼ���ڸ��ӵ��к��С�

ÿһ��������������� �ϣ��£��� ���� �� �ƶ�һ�����ӡ��㲻�ܽ���ǽ���ڵĸ��ӣ���Ҳ�����뿪�Թ������Ŀ�����ҵ��� entrance ��� �ĳ��ڡ����� �ĺ����� maze �߽� �ϵ� �ո��ӡ�entrance ���� ���� ���ڡ�

���㷵�ش� entrance ��������ڵ����·���� ���� �����������������·�������㷵�� -1 ��
*/
#define x first
#define y second

typedef pair<int, int> PII;

class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int n = maze.size(), m = maze[0].size(), INF = 1e8;
		vector<vector<int>> dist(n, vector<int>(m, INF));
		dist[entrance[0]][entrance[1]] = 0;
		queue<PII> q;
		q.push({ entrance[0],entrance[1] });
		int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
		while (q.size())
		{
			auto t = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int x = t.x + dx[i], y = t.y + dy[i];
				if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.' && dist[x][y] > dist[t.x][t.y] + 1)
				{
					dist[x][y] = dist[t.x][t.y] + 1;
					if (!x || x == n - 1 || !y || y == m - 1)
						return dist[x][y];
					q.push({ x,y });
				}
			}
		}
		return -1;
	}
};




/*
1926. �Թ������������ĳ���
����һ�� m x n ���Թ����� maze ���±�� 0 ��ʼ�����������пո��ӣ��� '.' ��ʾ����ǽ���� '+' ��ʾ����ͬʱ�����Թ������ entrance ���� entrance = [entrancerow, entrancecol] ��ʾ��һ��ʼ���ڸ��ӵ��к��С�

ÿһ��������������� �ϣ��£��� ���� �� �ƶ�һ�����ӡ��㲻�ܽ���ǽ���ڵĸ��ӣ���Ҳ�����뿪�Թ������Ŀ�����ҵ��� entrance ��� �ĳ��ڡ����� �ĺ����� maze �߽� �ϵ� �ո��ӡ�entrance ���� ���� ���ڡ�

���㷵�ش� entrance ��������ڵ����·���� ���� �����������������·�������㷵�� -1 ��
*/
class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int m = maze.size();
		int n = maze[0].size();
		queue<vector<int>> q;
		q.push(entrance);
		int steps = 0;
		maze[entrance[0]][entrance[1]] = 'x';
		vector<int> dir{ 0,-1,0,1,0 };
		while (!q.empty()) {
			int size = q.size();
			steps++;
			for (int i = 0; i < size; i++)
			{
				auto point = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int x = point[0] + dir[k], y = point[1] + dir[k + 1];
					if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
						if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
						{
							return steps;
						}
						q.push({ x,y });
						maze[x][y] = 'x';
					}
				}
			}
		}
		return -1;
	}
};

