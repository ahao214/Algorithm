#include<vector>
#include <numeric>

using namespace std;

/*
2316. ͳ������ͼ���޷����ൽ������

����һ������ n ����ʾһ�� ����ͼ ���� n ���ڵ㣬���Ϊ 0 �� n - 1 ��ͬʱ����һ����ά�������� edges ������ edges[i] = [ai, bi] ��ʾ�ڵ� ai �� bi ֮����һ�� ���� �ߡ�

���㷵�� �޷����ൽ�� �Ĳ�ͬ �����Ŀ ��
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
