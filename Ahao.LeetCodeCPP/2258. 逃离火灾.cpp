#include<vector>
#include<string>
#include <queue>

using namespace std;

/*
2258. �������

����һ���±�� 0 ��ʼ��СΪ m x n �Ķ�ά�������� grid ������ʾһ������ͼ��ÿ������Ϊ���� 3 ��ֵ֮һ��

0 ��ʾ�ݵء�
1 ��ʾ�Ż�ĸ��ӡ�
2 ��ʾһ��ǽ������𶼲���ͨ��������ӡ�
һ��ʼ���������Ͻǵĸ��� (0, 0) ������Ҫ���������½ǵİ�ȫ�ݸ��� (m - 1, n - 1) ��ÿһ���ӣ�������ƶ��� ���� �Ĳݵظ��ӡ�ÿ�����ƶ� ֮�� ���Ż�ĸ��ӻ���ɢ�����в���ǽ�� ���� ���ӡ�

���㷵�����ڳ�ʼλ�ÿ���ͣ���� ��� ����������ͣ�������ʱ����㻹�ܰ�ȫ���ﰲȫ�ݡ�����޷�ʵ�֣����㷵�� -1 ������������ڳ�ʼλ��ͣ����ã��� ���� �ܵ��ﰲȫ�ݣ����㷵�� 109 ��

ע�⣬����㵽�ﰲȫ�ݺ󣬻����ϵ��˰�ȫ�ݣ�����Ϊ���ܹ���ȫ���ﰲȫ�ݡ�

������������й�ͬ�ߣ���ô����Ϊ ���� ���ӡ�
*/


class Solution {
public:
    constexpr static int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    constexpr static int INF = 1e9;
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> fireTime(m, vector<int>(n, INF));
        /* ͨ�� bfs ���ÿ�������Ż��ʱ�� */
        bfs(grid, fireTime);
        /* �ҵ���㵽�յ�����ʱ�� */
        int arriveTime = getArriveTime(grid, fireTime, 0);
        /* ��ȫ�ݲ��ɴ� */
        if (arriveTime < 0) {
            return -1;
        }
        /* �𲻻ᵽ�ﰲȫ�� */
        if (fireTime[m - 1][n - 1] == INF) {
            return 1e9;
        }
        int ans = fireTime[m - 1][n - 1] - arriveTime;
        return getArriveTime(grid, fireTime, ans) >= 0 ? ans : (ans - 1);
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& fireTime) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    fireTime[i][j] = 0;
                }
            }
        }

        int time = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [cx, cy] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = cx + dirs[j][0];
                    int ny = cy + dirs[j][1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        if (grid[nx][ny] == 2 || fireTime[nx][ny] != INF) {
                            continue;
                        }
                        q.emplace(nx, ny);
                        fireTime[nx][ny] = time;
                    }
                }
            }
            time++;
        }
    }

    int getArriveTime(vector<vector<int>>& grid, vector<vector<int>>& fireTime, int stayTime) {
        int m = fireTime.size();
        int n = fireTime[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        q.emplace(0, 0, stayTime);
        visit[0][0] = true;
        while (!q.empty()) {
            auto [cx, cy, time] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = cx + dirs[j][0];
                int ny = cy + dirs[j][1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (grid[nx][ny] == 2 || visit[nx][ny]) {
                        continue;
                    }
                    if (nx == m - 1 && ny == n - 1) {
                        return time + 1;
                    }
                    if (fireTime[nx][ny] > time + 1) {
                        visit[nx][ny] = true;
                        q.emplace(nx, ny, time + 1);
                    }
                }
            }
        }
        return -1;
    }
};
