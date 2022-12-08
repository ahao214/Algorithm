#include<vector>

using namespace std;


/*
149. 直线上最多的点数
给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        // 点的数量不够
        if (len < 3) {
            return len;
        }
        int maxNum = 2;
        // 遍历每两个点
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                // 统计斜率相等个数
                int count = 2;
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                // 与其他点比较
                for (int k = j + 1; k < len; k++) {
                    // 如果斜率相等
                    if (dx * (points[i][1] - points[k][1]) == dy * (points[i][0] - points[k][0])) {
                        count++;
                    }
                }
                maxNum = max(maxNum, count);
                if (maxNum > len / 2) return maxNum;
            }
        }
        return maxNum;
    }
};