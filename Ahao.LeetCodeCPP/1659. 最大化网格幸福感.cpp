#include<vector>

using namespace std;


/*
1659. ��������Ҹ���

�����ĸ����� m��n��introvertsCount �� extrovertsCount ����һ�� m x n ���񣬺��������͵��ˣ�������˺�������ˡ��ܹ��� introvertsCount ��������˺� extrovertsCount ��������ˡ�

�������������Ӧ����ס�����ˣ���Ϊÿ���˷���һ������Ԫ�� ע�⣬���� �������˶������������С�

ÿ���˵� �Ҹ��� �������£�

������� ��ʼ ʱ�� 120 ���Ҹ��У���ÿ����һ���ھӣ�����Ļ�����ģ������� ʧȥ  30 ���Ҹ��С�
������� ��ʼ ʱ�� 40 ���Ҹ��У�ÿ����һ���ھӣ�����Ļ�����ģ������� �õ�  20 ���Ҹ��С�
�ھ���ָ��ס��һ�������ڵ�Ԫ���ϡ��¡������ĸ�ֱ�����ڵĵ�Ԫ�е������ˡ�

�����Ҹ��� ��ÿ�����Ҹ��е� �ܺ� �� ���� �����ܵ������Ҹ��� ��
*/

class Solution {
private:
    static constexpr int T = 243, N = 5, M = 6;
    int n, m, tot;
    int mask_bits[T][N];
    int iv_count[T], ev_count[T];
    int inner_score[T], inter_score[T][T];
    int d[N][T][M + 1][M + 1];

    // �ھӼ�ķ���
    static constexpr int score[3][3] = {
        {0, 0, 0},
        {0, -60, -10},
        {0, -10, 40}
    };

public:
    void init_data() {
        // �������ڷ���
        for (int mask = 0; mask < tot; mask++) {
            int mask_tmp = mask;
            for (int i = 0; i < n; i++) {
                int x = mask_tmp % 3;
                mask_bits[mask][i] = x;
                mask_tmp /= 3;
                if (x == 1) {
                    iv_count[mask]++;
                    inner_score[mask] += 120;
                }
                else if (x == 2) {
                    ev_count[mask]++;
                    inner_score[mask] += 40;
                }
                if (i > 0) {
                    inner_score[mask] += score[x][mask_bits[mask][i - 1]];
                }
            }
        }
        // �����м����
        for (int i = 0; i < tot; i++) {
            for (int j = 0; j < tot; j++) {
                inter_score[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    inter_score[i][j] += score[mask_bits[i][k]][mask_bits[j][k]];
                }
            }
        }
    }

    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->n = n;
        this->m = m;
        // ״̬����Ϊ 3^n
        this->tot = pow(3, n);

        init_data();
        // ���仯�������飬��ʼ��Ϊ -1����ʾδ��ֵ
        memset(d, -1, sizeof d);
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }

    int dfs(int row, int premask, int iv, int ev) {
        if (row == m || (iv == 0 && ev == 0)) {
            return 0;
        }
        // �����״̬�Ѿ�������𰸣���ֱ�ӷ���
        if (d[row][premask][iv][ev] != -1) {
            return d[row][premask][iv][ev];
        }
        // ʹ�����ã��򻯴���
        int& res = d[row][premask][iv][ev];
        // �Ϸ�״̬����ʼֵΪ 0
        res = 0;
        for (int mask = 0; mask < tot; mask++) {
            // mask �����������������ܳ��� iv �������������ܳ��� ev
            if (iv_count[mask] > iv || ev_count[mask] > ev) {
                continue;
            }
            res = max(res, dfs(row + 1, mask, iv - iv_count[mask], ev - ev_count[mask])
                + inner_score[mask]
                + inter_score[premask][mask]);
        }
        return res;
    }
};




class Solution {
private:
    static constexpr int T = 243, N = 5, M = 6;
    int n, m, tot;
    int p[N];
    int d[N * N][T][M + 1][M + 1];

    // �ھӼ�ķ���
    static constexpr int score[3][3] = {
        {0, 0, 0},
        {0, -60, -10},
        {0, -10, 40}
    };

public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->n = n;
        this->m = m;
        // ״̬����Ϊ 3^n
        this->tot = pow(3, n);
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] * 3;
        }

        // ���仯�������飬��ʼ��Ϊ -1����ʾδ��ֵ
        memset(d, -1, sizeof d);
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }

    int dfs(int pos, int mask, int iv, int ev) {
        if (pos == n * m || (iv == 0 && ev == 0)) {
            return 0;
        }
        int& res = d[pos][mask][iv][ev];
        if (res != -1) {
            return res;
        }
        res = 0;
        int up = mask / p[n - 1], left = mask % 3;
        // �����ڵ�һ�У������û��Ԫ�أ��� left ��Ϊ 0
        if (pos % n == 0) {
            left = 0;
        }
        for (int i = 0; i < 3; i++) {
            if ((i == 1 && iv == 0) || (i == 2 && ev == 0)) {
                continue;
            }
            int next_mask = mask % p[n - 1] * 3 + i;
            int score_sum = dfs(pos + 1, next_mask, iv - (i == 1), ev - (i == 2))
                + score[up][i]
                + score[left][i];
            if (i == 1) {
                score_sum += 120;
            }
            else if (i == 2) {
                score_sum += 40;
            }
            res = max(res, score_sum);
        }
        return res;
    }
};
