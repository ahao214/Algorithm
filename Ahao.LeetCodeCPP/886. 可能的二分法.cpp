#include<vector>

using namespace std;

/*
886. 可能的二分法

给定一组 n 人（编号为 1, 2, ..., n）， 我们想把每个人分进任意大小的两组。每个人都可能不喜欢其他人，那么他们不应该属于同一组。

给定整数 n 和数组 dislikes ，其中 dislikes[i] = [ai, bi] ，表示不允许将编号为 ai 和  bi的人归入同一组。当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。
*/

class Solution {
public:
    bool dfs(int curnode, int nowcolor, vector<int>& color, const vector<vector<int>>& g) {
        color[curnode] = nowcolor;
        for (auto& nextnode : g[curnode]) {
            if (color[nextnode] && color[nextnode] == color[curnode]) {
                return false;
            }
            if (!color[nextnode] && !dfs(nextnode, 3 ^ nowcolor, color, g)) {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, 0);
        vector<vector<int>> g(n + 1);
        for (auto& p : dislikes) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0 && !dfs(i, 1, color, g)) {
                return false;
            }
        }
        return true;
    }
};