#include<vector>
#include <queue>

using namespace std;

/*
2558. 从数量最多的堆取走礼物

给你一个整数数组 gifts ，表示各堆礼物的数量。每一秒，你需要执行以下操作：

选择礼物数量最多的那一堆。
如果不止一堆都符合礼物数量最多，从中选择任一堆即可。
选中的那一堆留下平方根数量的礼物（向下取整），取走其他的礼物。
返回在 k 秒后剩下的礼物数量。
*/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q(gifts.begin(), gifts.end());
        while (k--) {
            int x = q.top();
            q.pop();
            q.push(int(sqrt(x)));
        }
        long long res = 0;
        while (q.size()) {
            res += q.top();
            q.pop();
        }
        return res;
    }
};