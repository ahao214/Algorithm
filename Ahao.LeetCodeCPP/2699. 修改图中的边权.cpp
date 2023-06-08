#include<vector>

using namespace std;


/*
2699. 修改图中的边权

给你一个 n 个节点的 无向带权连通 图，节点编号为 0 到 n - 1 ，再给你一个整数数组 edges ，其中 edges[i] = [ai, bi, wi] 表示节点 ai 和 bi 之间有一条边权为 wi 的边。

部分边的边权为 -1（wi = -1），其他边的边权都为 正 数（wi > 0）。

你需要将所有边权为 -1 的边都修改为范围 [1, 2 * 109] 中的 正整数 ，使得从节点 source 到节点 destination 的 最短距离 为整数 target 。如果有 多种 修改方案可以使 source 和 destination 之间的最短距离等于 target ，你可以返回任意一种方案。

如果存在使 source 到 destination 最短距离为 target 的方案，请你按任意顺序返回包含所有边的数组（包括未修改边权的边）。如果不存在这样的方案，请你返回一个 空数组 。

注意：你不能修改一开始边权为正数的边。
*/



class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        int k = 0;
        for (const auto& e : edges) {
            if (e[2] == -1) {
                ++k;
            }
        }

        if (dijkstra(source, destination, construct(n, edges, 0, target)) > target) {
            return {};
        }
        if (dijkstra(source, destination, construct(n, edges, static_cast<long long>(k) * (target - 1), target)) < target) {
            return {};
        }

        long long left = 0, right = static_cast<long long>(k) * (target - 1), ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (dijkstra(source, destination, construct(n, edges, mid, target)) >= target) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        for (auto& e : edges) {
            if (e[2] == -1) {
                if (ans >= target - 1) {
                    e[2] = target;
                    ans -= (target - 1);
                }
                else {
                    e[2] = 1 + ans;
                    ans = 0;
                }
            }
        }

        return edges;
    }

    long long dijkstra(int source, int destination, const vector<vector<int>>& adj_matrix) {
        // 朴素的 dijkstra 算法
        // adj_matrix 是一个邻接矩阵
        int n = adj_matrix.size();
        vector<long long> dist(n, INT_MAX / 2);
        vector<int> used(n);
        dist[source] = 0;

        for (int round = 0; round < n - 1; ++round) {
            int u = -1;
            for (int i = 0; i < n; ++i) {
                if (!used[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }
            used[u] = true;
            for (int v = 0; v < n; ++v) {
                if (!used[v] && adj_matrix[u][v] != -1) {
                    dist[v] = min(dist[v], dist[u] + adj_matrix[u][v]);
                }
            }
        }

        return dist[destination];
    }

    vector<vector<int>> construct(int n, const vector<vector<int>>& edges, long long idx, int target) {
        // 需要构造出第 idx 种不同的边权情况，返回一个邻接矩阵
        vector<vector<int>> adj_matrix(n, vector<int>(n, -1));
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (w != -1) {
                adj_matrix[u][v] = adj_matrix[v][u] = w;
            }
            else {
                if (idx >= target - 1) {
                    adj_matrix[u][v] = adj_matrix[v][u] = target;
                    idx -= (target - 1);
                }
                else {
                    adj_matrix[u][v] = adj_matrix[v][u] = 1 + idx;
                    idx = 0;
                }
            }
        }
        return adj_matrix;
    }
};
