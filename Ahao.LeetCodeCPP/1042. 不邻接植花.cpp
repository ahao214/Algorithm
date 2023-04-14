#include<vector>

using namespace std;

/*
1042. 不邻接植花

有 n 个花园，按从 1 到 n 标记。另有数组 paths ，其中 paths[i] = [xi, yi] 描述了花园 xi 到花园 yi 的双向路径。在每个花园中，你打算种下四种花之一。

另外，所有花园 最多 有 3 条路径可以进入或离开.

你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。

以数组形式返回 任一 可行的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1、2、3、4 表示。保证存在答案。
*/

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for (auto& path : paths) {
            adj[path[0] - 1].emplace_back(path[1] - 1);
            adj[path[1] - 1].emplace_back(path[0] - 1);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            vector<bool> colored(5, false);
            for (auto& vertex : adj[i]) {
                colored[ans[vertex]] = true;
            }
            for (int j = 1; j <= 4; j++) {
                if (colored[j] == 0) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};
