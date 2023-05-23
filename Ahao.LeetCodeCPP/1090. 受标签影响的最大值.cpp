#include<vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
1090. 受标签影响的最大值

我们有一个 n 项的集合。给出两个整数数组 values 和 labels ，第 i 个元素的值和标签分别是 values[i] 和 labels[i]。还会给出两个整数 numWanted 和 useLimit 。

从 n 个元素中选择一个子集 s :

子集 s 的大小 小于或等于 numWanted 。
s 中 最多 有相同标签的 useLimit 项。
一个子集的 分数 是该子集的值之和。

返回子集 s 的最大 分数 。
*/


class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return values[i] > values[j];
            });

        int ans = 0, choose = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n && choose < numWanted; ++i) {
            int label = labels[id[i]];
            if (cnt[label] == useLimit) {
                continue;
            }
            ++choose;
            ans += values[id[i]];
            ++cnt[label];
        }
        return ans;
    }
};
