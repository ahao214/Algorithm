#include<vector>

using namespace std;


/*
947. 移除最多的同行或同列石头
n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。

如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头。

给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i 块石头的位置，返回 可以移除的石子 的最大数量。
*/
class Solution {
	bool isConnected(vector<int>& a, vector<int>& b) {
		return a[0] == b[0] || a[1] == b[1];
	}
	void dfs(vector<vector<int>>& connected, vector<int>& visited, int i)
	{
		visited[i] = 1;
		for (int& index : connected[i]) {
			if (visited[index] == 0) {
				dfs(connected, visited, index);
			}
		}
	}
public:
	int removeStones(vector<vector<int>>& stones) {
		int n = stones.size();
		vector<vector<int> > connected(n);
		vector<int> visited(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (isConnected(stones[i], stones[j])) {
					connected[i].push_back(j);
					connected[j].push_back(i);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == 0)
			{
				cnt++;
				dfs(connected, visited, i);
			}
		}
		return n - cnt;
	}
};