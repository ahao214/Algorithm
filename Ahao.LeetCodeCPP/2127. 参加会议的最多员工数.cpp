#include <queue>
#include<vector>

using namespace std;

/*
2127. �μӻ�������Ա����

һ����˾׼����֯һ�����飬������������ n λԱ������˾׼����һ�� Բ�� �����ӣ��������� ������Ŀ ��Ա����

Ա�����Ϊ 0 �� n - 1 ��ÿλԱ������һλ ϲ�� ��Ա����ÿλԱ�� ���ҽ��� ����������ϲ��Ա�����Աߣ����Ż�μӻ��顣ÿλԱ��ϲ����Ա�� ���� �����Լ���

����һ���±�� 0 ��ʼ���������� favorite ������ favorite[i] ��ʾ�� i λԱ��ϲ����Ա�������㷵�زμӻ���� ���Ա����Ŀ ��
*/


class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        // ͳ����ȣ����ڽ�����������
        vector<int> indeg(n);
        for (int i = 0; i < n; ++i) {
            ++indeg[favorite[i]];
        }
        vector<int> used(n), f(n, 1);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            used[u] = true;
            q.pop();
            int v = favorite[u];
            // ״̬ת��
            f[v] = max(f[v], f[u] + 1);
            --indeg[v];
            if (!indeg[v]) {
                q.push(v);
            }
        }
        // ring ��ʾ���Ļ��Ĵ�С
        // total ��ʾ���л���СΪ 2 �ġ��������������ϵ���ġ�˫�����ߡ�·��֮��
        int ring = 0, total = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                int j = favorite[i];
                // favorite[favorite[i]] = i ˵�����Ĵ�СΪ 2
                if (favorite[j] == i) {
                    total += f[i] + f[j];
                    used[i] = used[j] = true;
                }
                // ���򻷵Ĵ�С����Ϊ 3��������Ҫ�ҳ���
                else {
                    int u = i, cnt = 0;
                    while (true) {
                        ++cnt;
                        u = favorite[u];
                        used[u] = true;
                        if (u == i) {
                            break;
                        }
                    }
                    ring = max(ring, cnt);
                }
            }
        }
        return max(ring, total);
    }
};
