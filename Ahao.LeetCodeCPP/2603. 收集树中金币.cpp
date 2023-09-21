#include<vector>
#include <queue>

using namespace std;


/*
2603. �ռ����н��

����һ�� n ���ڵ�������޸������ڵ��Ŵ� 0 �� n - 1 ���������� n ��һ������Ϊ n - 1 �Ķ�ά�������� edges ������ edges[i] = [ai, bi] ��ʾ���нڵ� ai �� bi ֮����һ���ߡ��ٸ���һ������Ϊ n ������ coins ������ coins[i] ����Ϊ 0 Ҳ����Ϊ 1 ��1 ��ʾ�ڵ� i ����һ����ҡ�

һ��ʼ������Ҫѡ����������һ���ڵ�����������ִ��������������Σ�

�ռ����뵱ǰ�ڵ����Ϊ 2 ���ڵ����н�ң�����
�ƶ�������һ�����ڽڵ㡣
����Ҫ�ռ��������еĽ�ң����һص������ڵ㣬���㷵�����پ����ı�����

������ξ���һ���ߣ�ÿһ�ξ���������𰸼�һ��
*/



class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> g(n);
        vector<int> degree(n);
        for (const auto& edge : edges) {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
            ++degree[x];
            ++degree[y];
        }

        int rest = n;
        {
            /* ɾ�����������޽�ҵ�Ҷ�ӽڵ㣬ֱ���������е�Ҷ�ӽڵ㶼�Ǻ��н�ҵ� */
            queue<int> q;
            for (int i = 0; i < n; ++i) {
                if (degree[i] == 1 && !coins[i]) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int u = q.front();
                --degree[u];
                q.pop();
                --rest;
                for (int v : g[u]) {
                    --degree[v];
                    if (degree[v] == 1 && !coins[v]) {
                        q.push(v);
                    }
                }
            }
        }
        {
            /* ɾ���������е�Ҷ�ӽڵ�, ����ɾ��2�� */
            for (int _ = 0; _ < 2; ++_) {
                queue<int> q;
                for (int i = 0; i < n; ++i) {
                    if (degree[i] == 1) {
                        q.push(i);
                    }
                }
                while (!q.empty()) {
                    int u = q.front();
                    --degree[u];
                    q.pop();
                    --rest;
                    for (int v : g[u]) {
                        --degree[v];
                    }
                }
            }
        }

        return rest == 0 ? 0 : (rest - 1) * 2;
    }
};

