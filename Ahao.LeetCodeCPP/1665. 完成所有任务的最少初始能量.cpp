#include<vector>
#include <algorithm>

using namespace std;


/*
1665. 完成所有任务的最少初始能量
给你一个任务数组 tasks ，其中 tasks[i] = [actuali, minimumi] ：

actuali 是完成第 i 个任务 需要耗费 的实际能量。
minimumi 是开始第 i 个任务前需要达到的最低能量。
比方说，如果任务为 [10, 12] 且你当前的能量为 11 ，那么你不能开始这个任务。如果你当前的能量为 13 ，你可以完成这个任务，且完成它后剩余能量为 3 。

你可以按照 任意顺序 完成任务。

请你返回完成所有任务的 最少 初始能量。
*/
class Solution {
public:
	/*
	按照minimumi - actuali从小到大排序
	定义W是完成某个任务后剩余的能量
	完成前：W + actuali >= minimumi
	W >= minimumi - actuali
	W的值就是任务数组中每个任务的minimumi - actuali从小到大的值的和
	*/
	int minimumEffort(vector<vector<int>>& tasks) {
		sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
			return a[1] - a[0] < b[1] - b[0];
			});

		int w = 0, s = 0;
		for (auto& t : tasks)
		{
			int x = t[0], y = t[1];
			s += x;
			w = max(w, y - s);
		}
		for (auto& t : tasks) w += t[0];
		return w;
	}
};