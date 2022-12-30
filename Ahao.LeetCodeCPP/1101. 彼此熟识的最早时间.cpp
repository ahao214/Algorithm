#include<vector>
#include <algorithm>

using namespace std;



class Solution {
	vector<int> parent;
	int find(int x) {
		if (x != parent[x]) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unionSet(int x, int y) {
		parent[find(x)] = find(y);
	}

	bool isConnected(int x, int y) {
		return find(x) == find(y);
	}

public:
	int earliestAcq(vector<vector<int>>& logs, int n) {
		sort(logs.begin(), logs.end(), [&](vector<int>& a, vector<int>& b) {
			if (a[0] == b[0]) {
				return a[1] == b[1] ? a[2] < b[2] : a[1] < b[1];
			}
			return a[0] < b[0];
			});
		for (int i = 0; i < n; i++) {
			parent[i].push_back(i);
		}
		int cnt = n;
		for (auto log : logs) {
			int x = log[1], y = log[2];
			if (!isConnected(x, y)) {
				unionSet(x, y);
				cnt--;
			}
			if (cnt == 1) {
				return log[0];
			}
		}
		return -1;
	}
};
