#include<vector>
#include <numeric>

using namespace std;

/*
2316. 统计无向图中无法互相到达点对数

给你一个整数 n ，表示一张 无向图 中有 n 个节点，编号为 0 到 n - 1 。同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 无向 边。

请你返回 无法互相到达 的不同 点对数目 。
*/


class UnionFind {
private:
    vector<int> parents;
    vector<int> sizes;
public:
    UnionFind(int n) : parents(n), sizes(n, 1) {
        iota(parents.begin(), parents.end(), 0);
    }
    int Find(int x) {
        if (parents[x] == x) {
            return x;
        }
        return parents[x] = Find(parents[x]);
    }
    void Union(int x, int y) {
        int rx = Find(x), ry = Find(y);
        if (rx != ry) {
            if (sizes[rx] > sizes[ry]) {
                parents[ry] = rx;
                sizes[rx] += sizes[ry];
            }
            else {
                parents[rx] = ry;
                sizes[ry] += sizes[rx];
            }
        }
    }
    int GetSize(int x) {
        return sizes[x];
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (const auto& edge : edges) {
            uf.Union(edge[0], edge[1]);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += n - uf.GetSize(uf.Find(i));
        }
        return res / 2;
    }
};
