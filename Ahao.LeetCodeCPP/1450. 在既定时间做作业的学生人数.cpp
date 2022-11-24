#include<vector>
#include <random>

using namespace std;


/*
1450. 在既定时间做作业的学生人数
给你两个整数数组 startTime（开始时间）和 endTime（结束时间），并指定一个整数 queryTime 作为查询时间。

已知，第 i 名学生在 startTime[i] 时开始写作业并于 endTime[i] 时完成作业。

请返回在查询时间 queryTime 时正在做作业的学生人数。形式上，返回能够使 queryTime 处于区间 [startTime[i], endTime[i]]（含）的学生人数。
*/

//枚举
class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int n = startTime.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
				ans++;
			}
		}
		return ans;
	}
};


//差分数组
class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int n = startTime.size();
		int maxEndTime = *max_element(endTime.begin(), endTime.end());
		if (queryTime > maxEndTime) {
			return 0;
		}
		vector<int> cnt(maxEndTime + 2);
		for (int i = 0; i < n; i++) {
			cnt[startTime[i]]++;
			cnt[endTime[i] + 1]--;
		}
		int ans = 0;
		for (int i = 0; i <= queryTime; i++) {
			ans += cnt[i];
		}
		return ans;
	}
};


class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int res = 0;
		for (int i = 0; i < startTime.size(); i++)
		{
			if (startTime[i] <= queryTime && queryTime <= endTime[i])
				res++;
		}
		return res;
	}
};

