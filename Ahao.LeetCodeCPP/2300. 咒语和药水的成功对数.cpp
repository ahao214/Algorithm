#include<vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
2300. 咒语和药水的成功对数

给你两个正整数数组 spells 和 potions ，长度分别为 n 和 m ，其中 spells[i] 表示第 i 个咒语的能量强度，potions[j] 表示第 j 瓶药水的能量强度。

同时给你一个整数 success 。一个咒语和药水的能量强度 相乘 如果 大于等于 success ，那么它们视为一对 成功 的组合。

请你返回一个长度为 n 的整数数组 pairs，其中 pairs[i] 是能跟第 i 个咒语成功组合的 药水 数目。

*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (auto& i : spells) {
            long long t = (success + i - 1) / i - 1;
            res.push_back(potions.size() - (upper_bound(potions.begin(), potions.end(), t) - potions.begin()));
        }
        return res;
    }
};


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size());
        vector<int> idx(spells.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return spells[a] < spells[b];
            });
        sort(potions.begin(), potions.end(), [](int a, int b) {
            return a > b;
            });
        for (int i = 0, j = 0; i < spells.size(); ++i) {
            int p = idx[i];
            int v = spells[p];
            while (j < potions.size() && (long long)potions[j] * v >= success) {
                ++j;
            }
            res[p] = j;
        }
        return res;
    }
};
