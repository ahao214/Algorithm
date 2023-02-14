#include<vector>
#include <unordered_map>
#include <stack>

using namespace std;

/*
1124. 表现良好的最长时间段

给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。

我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。

所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。

请你返回「表现良好时间段」的最大长度。
*/

//贪心
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> s(n + 1);
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if (s[stk.top()] > s[i]) {
                stk.push(i);
            }
        }

        int res = 0;
        for (int r = n; r >= 1; r--) {
            while (stk.size() && s[stk.top()] < s[r]) {
                res = max(res, r - stk.top());
                stk.pop();
            }
        }
        return res;
    }
};



//哈希表
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int, int> ump;
        int s = 0, res = 0;
        for (int i = 0; i < n; i++) {
            s += hours[i] > 8 ? 1 : -1;
            if (s > 0) {
                res = max(res, i + 1);
            }
            else {
                if (ump.count(s - 1)) {
                    res = max(res, i - ump[s - 1]);
                }
            }
            if (!ump.count(s)) {
                ump[s] = i;
            }
        }
        return res;
    }
};
