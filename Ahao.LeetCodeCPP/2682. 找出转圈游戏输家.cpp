#include<vector>
using namespace std;


/*
2682. 找出转圈游戏输家

n 个朋友在玩游戏。这些朋友坐成一个圈，按 顺时针方向 从 1 到 n 编号。从第 i 个朋友的位置开始顺时针移动 1 步会到达第 (i + 1) 个朋友的位置（1 <= i < n），而从第 n 个朋友的位置开始顺时针移动 1 步会回到第 1 个朋友的位置。

游戏规则如下：

第 1 个朋友接球。

接着，第 1 个朋友将球传给距离他顺时针方向 k 步的朋友。
然后，接球的朋友应该把球传给距离他顺时针方向 2 * k 步的朋友。
接着，接球的朋友应该把球传给距离他顺时针方向 3 * k 步的朋友，以此类推。
换句话说，在第 i 轮中持有球的那位朋友需要将球传递给距离他顺时针方向 i * k 步的朋友。

当某个朋友第 2 次接到球时，游戏结束。

在整场游戏中没有接到过球的朋友是 输家 。

给你参与游戏的朋友数量 n 和一个整数 k ，请按升序排列返回包含所有输家编号的数组 answer 作为答案。
*/



class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visit(n, false);
        for (int i = k, j = 0; !visit[j]; i += k) {
            visit[j] = true;
            j = (j + i) % n;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};
