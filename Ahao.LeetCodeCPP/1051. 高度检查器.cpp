using namespace std;

#include<vector>
#include <algorithm>


/// <summary>
/// 基于比较的排序
/// </summary>
class Solution {
public:
	int heightChecker(vector<int>& heights) {
		vector<int> expected(heights);
		sort(expected.begin(), expected.end());
		int n = heights.size(), ans = 0;
		for (int i = 0; i < n; ++i) {
			if (heights[i] != expected[i]) {
				++ans;
			}
		}
		return ans;
	}
};


/// <summary>
/// 计数排序
/// </summary>
class Solution {
public:
	int heightChecker(vector<int>& heights) {
		int m = *max_element(heights.begin(), heights.end());
		vector<int> cnt(m + 1);
		for (int h : heights) {
			++cnt[h];
		}

		int idx = 0, ans = 0;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= cnt[i]; ++j) {
				if (heights[idx] != i) {
					++ans;
				}
				++idx;
			}
		}
		return ans;
	}
};
