#include<vector>
#include <algorithm>

using namespace std;


/*
2171. 拿出最少数目的魔法豆
给你一个 正 整数数组 beans ，其中每个整数表示一个袋子里装的魔法豆的数目。
请你从每个袋子中 拿出 一些豆子（也可以不拿出），使得剩下的 非空 袋子中（即 至少 还有 一颗 魔法豆的袋子）魔法豆的数目 相等 。一旦魔法豆从袋子中取出，你不能将它放到任何其他的袋子中。

请你返回你需要拿出魔法豆的 最少数目。
*/
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += beans[i];
        long long ans = sum - 1LL * n * beans[0], pre = 0;
        for (int i = 0; i < n; i++) {
            pre += beans[i];
            sum -= beans[i];
            if (i != n - 1)
                ans = min(ans, pre + sum - 1LL * (n - i - 1) * beans[i + 1]);
        }
        return ans;
    }
};