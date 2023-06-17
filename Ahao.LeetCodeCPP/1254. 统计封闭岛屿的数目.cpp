#include<vector>
#include <queue>

using namespace std;

/*
1254. ͳ�Ʒ�յ������Ŀ

��ά���� grid �� 0 �����أ��� 1 ��ˮ����ɡ�����������4��������ͨ�� 0 ��ɵ�Ⱥ����յ���һ�� ��ȫ ��1��Χ�����ϡ��ҡ��£��ĵ���

�뷵�� ��յ��� ����Ŀ��
*/

class Solution {
public:
    static constexpr int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    queue<pair<int, int>> qu;
                    grid[i][j] = 1;
                    bool closed = true;

                    qu.push(make_pair(i, j));
                    while (!qu.empty()) {
                        auto [cx, cy] = qu.front();
                        qu.pop();
                        if (cx == 0 || cy == 0 || cx == m - 1 || cy == n - 1) {
                            closed = false;
                        }
                        for (int i = 0; i < 4; i++) {
                            int nx = cx + dir[i][0];
                            int ny = cy + dir[i][1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                                grid[nx][ny] = 1;
                                qu.emplace(nx, ny);
                            }
                        }
                    }
                    if (closed) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};