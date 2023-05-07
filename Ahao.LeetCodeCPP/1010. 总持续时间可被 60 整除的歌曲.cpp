#include<vector>

using namespace std;


/*
1010. 总持续时间可被 60 整除的歌曲

在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。

返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望下标数字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0。
*/


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for (int t : time) {
            cnt[t % 60]++;
        }
        long long res = 0;
        for (int i = 1; i < 30; i++) {
            res += cnt[i] * cnt[60 - i];
        }
        res += (long long)cnt[0] * (cnt[0] - 1) / 2 + (long long)cnt[30] * (cnt[30] - 1) / 2;
        return (int)res;
    }
};
