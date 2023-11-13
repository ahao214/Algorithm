#include<vector>
#include <algorithm>

using namespace std;




/*
2589. 完成所有任务的最少时间

你有一台电脑，它可以 同时 运行无数个任务。给你一个二维整数数组 tasks ，其中 tasks[i] = [starti, endi, durationi] 表示第 i 个任务需要在 闭区间 时间段 [starti, endi] 内运行 durationi 个整数时间点（但不需要连续）。

当电脑需要运行任务时，你可以打开电脑，如果空闲时，你可以将电脑关闭。

请你返回完成所有任务的情况下，电脑最少需要运行多少秒。
*/
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks)
    {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
            });

        vector<int>time(2005);
        for (int i = 0; i < tasks.size(); i++)
        {
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];
            int overlap = 0;
            for (int t = start; t <= end; t++)
                overlap += (time[t] == 1);

            if (overlap >= duration) continue;
            int diff = duration - overlap;
            for (int t = end; t >= start; t--)
            {
                if (time[t] == 0)
                {
                    time[t] = 1;
                    diff--;
                }
                if (diff == 0)
                    break;
            }
        }

        int ret = 0;
        for (int t = 0; t <= 2000; t++)
            ret += (time[t] == 1);
        return ret;
    }
};

using AI3 = array<int, 3>;
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks)
    {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
            });

        vector<AI3>arr;
        arr.push_back({ -2,-1,0 });

        for (int i = 0; i < tasks.size(); i++)
        {
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];

            auto iter = lower_bound(arr.begin(), arr.end(), AI3({ start,0,0 }));
            iter = prev(iter);

            int overlap;
            if ((*iter)[1] < start)
                overlap = arr.back()[2] - (*iter)[2];
            else
                overlap = arr.back()[2] - (*iter)[2] + abs((*iter)[1] - start + 1);

            int diff = duration - overlap;
            int cur = end;
            while (diff > 0)
            {
                if (abs(arr.back()[1] - cur) < diff)
                {
                    diff -= abs(arr.back()[1] - cur);
                    cur = arr.back()[0] - 1;
                    arr.pop_back();
                }
                else
                {
                    arr.push_back({ cur - diff + 1, end, arr.back()[2] + end - (cur - diff) });
                    diff = 0;
                }
            }
        }

        return arr.back()[2];
    }
};

