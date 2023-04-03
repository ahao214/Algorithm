#include<vector>

using namespace std;

/*
1000. �ϲ�ʯͷ����ͳɱ�

�� N ��ʯͷ�ų�һ�ţ��� i ������ stones[i] ��ʯͷ��

ÿ���ƶ���move����Ҫ�������� K ��ʯͷ�ϲ�Ϊһ�ѣ�������ƶ��ĳɱ�Ϊ�� K ��ʯͷ��������

�ҳ�������ʯͷ�ϲ���һ�ѵ���ͳɱ�����������ܣ����� -1 ��
*/

class Solution {
    static constexpr int inf = 0x3f3f3f3f;
    vector<vector<vector<int>>> d;
    vector<int> sum;
    int k;
public:
    int get(int l, int r, int t) {
        // �� d[l][r][t] ��Ϊ -1����ʾ�Ѿ���֮ǰ�ĵݹ鱻������ֱ�ӷ��ش�
        if (d[l][r][t] != -1) {
            return d[l][r][t];
        }
        // ��ʯͷ����С�� t ʱ��һ���޽�
        if (t > r - l + 1) {
            return inf;
        }
        if (t == 1) {
            int res = get(l, r, k);
            if (res == inf) {
                return d[l][r][t] = inf;
            }
            return d[l][r][t] = res + (sum[r] - (l == 0 ? 0 : sum[l - 1]));
        }
        int val = inf;
        for (int p = l; p < r; p += (k - 1)) {
            val = min(val, get(l, p, 1) + get(p + 1, r, t - 1));
        }
        return d[l][r][t] = val;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }
        this->k = k;
        d = vector(n, vector(n, vector<int>(k + 1, -1)));
        sum = vector<int>(n, 0);

        // ��ʼ��
        for (int i = 0, s = 0; i < n; i++) {
            d[i][i][1] = 0;
            s += stones[i];
            sum[i] = s;
        }
        int res = get(0, n - 1, 1);
        return res;
    }
};
