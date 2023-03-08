#include<vector>
#include<algorithm>


using namespace std;

//方法一：贪心
class Solution {
public:
	void help(vector<vector<int>>& intervals, vector<vector<int>>& temp, int pos, int num) {
		for (int i = pos; i >= 0; i--) {
			if (intervals[i][1] < num) {
				break;
			}
			temp[i].push_back(num);
		}
	}

	int intersectionSizeTwo(vector<vector<int>>& intervals) {
		int n = intervals.size();
		int res = 0;
		int m = 2;
		sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
			if (a[0] == b[0]) {
				return a[1] > b[1];
			}
			return a[0] < b[0];
			});
		vector<vector<int>> temp(n);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = intervals[i][0], k = temp[i].size(); k < m; j++, k++) {
				res++;
				help(intervals, temp, i - 1, j);
			}
		}
		return res;
	}
};




/*
757. 设置交集大小至少为2
*/
class Solution {
public:
	int intersectionSizeTwo(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
			if (a[1] != b[1])
				return a[1] < b[1];
			return a[0] > b[0];
			});

		vector<int> q(1, -1);
		int cnt = 0;
		for (auto& r : intervals)
		{
			if (r[0] > q[cnt])
			{
				q.push_back(r[1] - 1);
				q.push_back(r[1]);
				cnt += 2;
			}
			else if (r[0] > q[cnt - 1])
			{
				q.push_back(r[1]);
				cnt++;
			}
		}
		return cnt;
	}
};
