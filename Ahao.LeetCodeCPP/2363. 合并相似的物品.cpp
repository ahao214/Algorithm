#include<vector>
#include <map>

using namespace std;

/*
2363. 合并相似的物品

给你两个二维整数数组 items1 和 items2 ，表示两个物品集合。每个数组 items 有以下特质：

items[i] = [valuei, weighti] 其中 valuei 表示第 i 件物品的 价值 ，weighti 表示第 i 件物品的 重量 。
items 中每件物品的价值都是 唯一的 。
请你返回一个二维数组 ret，其中 ret[i] = [valuei, weighti]， weighti 是所有价值为 valuei 物品的 重量之和 。

注意：ret 应该按价值 升序 排序后返回。
*/

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (auto& v : items1) {
            mp[v[0]] += v[1];
        }
        for (auto& v : items2) {
            mp[v[0]] += v[1];
        }

        vector<vector<int>> res;
        for (auto& [k, v] : mp) {
            res.push_back({ k, v });
        }
        return res;
    }
};
