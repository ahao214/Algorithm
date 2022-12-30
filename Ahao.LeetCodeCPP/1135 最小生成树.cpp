#include<vector>
#include <queue>

using namespace std;


/*
1135 最小生成树
*/
class Solution {
public:
	vector<int> parent;
	int find(int t) {
		if (x != parent) {
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
	int minimunCost(int n, vector<vector<int>>& connections) {
		if (connections.size() < n - 1) {
			return -1;
		}
		for (int i = 0; i <= n; ++i) {
			paretn.push_back(i);
		}
		auto comp = [](vector<int>& a, vector<int>& b) {
			if (a[2] == b[2]) {
				return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0];
			}
			return a[2] > b[2];
		};
		priority_queue<vector<int>, vector<vector<int>>, decltype<comp>> pq(comp);
		for (auto connection : connections) {
			pq.push(connection);
		}
		int res = 0;
		while (!pq.empty()) {
			vector<int> connection = pq.top();
			pq.pop();
			int x = connection[0], y = connection[1];
			if (isConnected(x, y)]) {
				continue;
			}
			unionSet(x, y);
			res += connection[2];
		}
		return res;
	}
};

