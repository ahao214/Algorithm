#include<vector>
#include <algorithm>

using namespace std;


/*
1024. 视频拼接

你将会获得一系列视频片段，这些片段来自于一项持续时长为 time 秒的体育赛事。这些片段可能有所重叠，也可能长度不一。

使用数组 clips 描述所有的视频片段，其中 clips[i] = [starti, endi] 表示：某个视频片段开始于 starti 并于 endi 结束。

甚至可以对这些片段自由地再剪辑：

例如，片段 [0, 7] 可以剪切成 [0, 1] + [1, 3] + [3, 7] 三部分。
我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（[0, time]）。返回所需片段的最小数目，如果无法完成该任务，则返回 -1 。
*/
class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int time) {
		sort(clips.begin(), clips.end(), [&](vector<int>& a, vector<int>& b) {
			return a[0] < b[0];
			});

		int res = 0, last = 0;
		for (int i = 0; i < clips.size();)
		{
			if (clips[i][0] > last) return -1;
			int r = 0;
			while (i < clips.size() && clips[i][0] <= last)
			{
				r = max(r, clips[i][1]);
				i++;
			}
			last = r;
			res++;
			if (last >= time) break;
		}
		if (last >= time) return res;
		return -1;
	}
};
