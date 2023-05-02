#include<vector>
#include <unordered_set>


using namespace std;

/*
970. 强整数

给定三个整数 x 、 y 和 bound ，返回 值小于或等于 bound 的所有 强整数 组成的列表 。

如果某一整数可以表示为 xi + yj ，其中整数 i >= 0 且 j >= 0，那么我们认为该整数是一个 强整数 。

你可以按 任何顺序 返回答案。在你的回答中，每个值 最多 出现一次。

*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> cnt;
        int value1 = 1;
        for (int i = 0; i < 21; i++) {
            int value2 = 1;
            for (int j = 0; j < 21; j++) {
                int value = value1 + value2;
                if (value <= bound) {
                    cnt.emplace(value);
                }
                else {
                    break;
                }
                value2 *= y;
            }
            if (value1 > bound) {
                break;
            }
            value1 *= x;
        }
        return vector<int>(cnt.begin(), cnt.end());
    }
};
