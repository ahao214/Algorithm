#include<vector>
#include <queue>

using namespace std;


/*
1654. ���ҵ�������Ծ����
��һֻ����ļ��������ϵ�λ�� x ���������������λ�� 0 �������������ļҡ�

������Ծ�Ĺ������£�

������ ��ǰ ��ǡ�� a ��λ�ã�������������
������ ���� ��ǡ�� b ��λ�ã�������������
������ ���� ������ 2 �Ρ�
�����������κ� forbidden �����е�λ�á�
���������ǰ�� ���� ���ļҵ�λ�ã������� �������������� ��λ�á�

����һ���������� forbidden ������ forbidden[i] �����鲻��������λ�ã�ͬʱ�������� a�� b �� x �����㷵�����鵽�ҵ�������Ծ���������û��ǡ�õ��� x �Ŀ��з��������㷵�� -1 ��

*/
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // ��Զ���� bound = max(F + a + b, x + b)
        int F = *max_element(forbidden.begin(), forbidden.end()), bound = max(F + a + b, x + b);

        int ban[bound + 1];
        memset(ban, 0, sizeof(ban));
        for (int f : forbidden) {
            ban[f] = 1;
        }

        int dist[bound + 1][2]; // dist[i][0] - ��һ��ǰ��, dist[i][1] - ��һ�κ���
        memset(dist, 0x3f, sizeof(dist));
        dist[0][0] = 0;
        queue<pair<int, int>> q({ {0, 0} });
        while (q.size()) {
            auto [i, pre;] = q.front(); q.pop();
            if (i == x) {
                return dist[i][pre];
            }
            if (pre == 0 && i - b >= 0 && !ban[i - b] && dist[i][pre] + 1 < dist[i - b][1]) {
                dist[i - b][1] = dist[i][pre] + 1;
                q.emplace(i - b, 1);
            }
            if (i + a <= bound && !ban[i + a] && dist[i][pre] + 1 < dist[i + a][0]) {
                dist[i + a][0] = dist[i][pre] + 1;
                q.emplace(i + a, 0);
            }
        }

        return -1;
    }
};