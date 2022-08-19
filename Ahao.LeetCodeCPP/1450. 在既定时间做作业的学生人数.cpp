#include<vector>
#include <random>

using namespace std;


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
