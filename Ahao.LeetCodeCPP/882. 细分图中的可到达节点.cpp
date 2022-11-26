#include<vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/*
882. ϸ��ͼ�еĿɵ���ڵ�

����һ������ͼ��ԭʼͼ����ͼ���� n ���ڵ㣬��Ŵ� 0 �� n - 1 ���������ͼ�е�ÿ���� ϸ�� Ϊһ���ڵ�����ÿ����֮����½ڵ���������ͬ��

ͼ���ɱ���ɵĶ�ά���� edges ��ʾ������ edges[i] = [ui, vi, cnti] ��ʾԭʼͼ�нڵ� ui �� vi ֮�����һ���ߣ�cnti �ǽ��� ϸ�� ����½ڵ�������ע�⣬cnti == 0 ��ʾ�߲���ϸ�֡�

Ҫ ϸ�� �� [ui, vi] ����Ҫ�����滻Ϊ (cnti + 1) ���±ߣ��� cnti ���½ڵ㡣�½ڵ�Ϊ x1, x2, ..., xcnti ���±�Ϊ [ui, x1], [x1, x2], [x2, x3], ..., [xcnti+1, xcnti], [xcnti, vi] ��

���ڵõ�һ�� �µ�ϸ��ͼ ���������ӽڵ� 0 ���������Ե�����ٸ��ڵ㣿����ڵ������� maxMoves ����٣�����Ϊ ���Ե��� ��

����ԭʼͼ�� maxMoves ������ �µ�ϸ��ͼ�дӽڵ� 0 ���� �ɵ���Ľڵ��� ��
*/

class Solution {
public:
    int encode(int u, int v, int n) {
        return u * n + v;
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adList(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], nodes = edge[2];
            adList[u].emplace_back(v, nodes);
            adList[v].emplace_back(u, nodes);
        }

        unordered_map<int, int> used;
        unordered_set<int> visited;
        int reachableNodes = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        while (!pq.empty() && pq.top().first <= maxMoves) {
            auto [step, u] = pq.top();
            pq.pop();
            if (visited.count(u)) {
                continue;
            }
            visited.emplace(u);
            reachableNodes++;
            for (auto [v, nodes] : adList[u]) {
                if (nodes + step + 1 <= maxMoves && !visited.count(v)) {
                    pq.emplace(nodes + step + 1, v);
                }
                used[encode(u, v, n)] = min(nodes, maxMoves - step);
            }
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], nodes = edge[2];
            reachableNodes += min(nodes, used[encode(u, v, n)] + used[encode(v, u, n)]);
        }
        return reachableNodes;
    }
};
