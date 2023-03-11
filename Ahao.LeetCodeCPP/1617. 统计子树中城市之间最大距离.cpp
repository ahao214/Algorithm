#include<vector>
#include<queue>
#include <functional>

using namespace std;


/*
1617. ͳ�������г���֮��������

���� n �����У����Ϊ�� 1 �� n ��ͬʱ����һ����СΪ n-1 ������ edges ������ edges[i] = [ui, vi] ��ʾ���� ui �� vi ֮����һ��˫��ߡ���Ŀ��֤�������֮��ֻ��Ψһ��һ��·�������仰˵�����г����γ���һ�� �� ��

һ�� ���� �ǳ��е�һ���Ӽ������Ӽ����������֮�����ͨ���Ӽ��е��������кͱߵ��������������Ϊ��һ����������������һ������������һ�������д��ڣ�������һ�������в����ڡ�

���� d �� 1 �� n-1 �������ҵ����м� ������ ǡ��Ϊ d ������������Ŀ��

���㷵��һ����СΪ n-1 �����飬���е� d ��Ԫ�أ��±�� 1 ��ʼ���ǳ��м� ������ ǡ�õ��� d ��������Ŀ��

��ע�⣬�������м���붨��Ϊ����֮����Ҫ�����ıߵ���Ŀ��
*/

class Solution {
	vector<vector<int>>adj;
public:
	vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges)
	{
		adj.resize(n);
		for (auto edge : edges)
		{
			adj[edge[0] - 1].push_back(edge[1] - 1);
			adj[edge[1] - 1].push_back(edge[0] - 1);
		}

		vector<int>allow(n);
		vector<int>rets(n, 0);
		vector<int>dist(n);
		for (int state = 1; state < (1 << n); state++)
		{
			int start;
			int count = 0;
			for (int i = 0; i < n; i++)
			{
				if (((state >> i) & 1) == 1)
				{
					allow[i] = 1;
					start = i;
					count++;
				}
				else
					allow[i] = 0;
			}

			for (int i = 0; i < n; i++)
				dist[i] = -1;
			int v1 = bfs(start, dist, allow);

			int countVisited = 0;
			for (int i = 0; i < n; i++)
				countVisited += (dist[i] != -1);
			if (countVisited != count)
				continue;

			for (int i = 0; i < n; i++)
				dist[i] = -1;
			int v2 = bfs(v1, dist, allow);
			int maxDist = *max_element(dist.begin(), dist.end());

			rets[maxDist]++;
		}

		rets.erase(rets.begin());
		return rets;
	}

	int bfs(int start, vector<int>& dis, vector<int>& allow)
	{
		int n = dis.size();
		queue<int> q;
		q.push(start);
		dis[start] = 0;
		int maxDis = 0;
		int maxId = start;

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			for (auto next : adj[cur])
			{
				if (allow[next] == 0) continue;
				if (dis[next] == -1)
				{
					q.push(next);
					dis[next] = dis[cur] + 1;
					if (dis[next] > maxDis)
					{
						maxDis = dis[next];
						maxId = next;
					}
				}
			}
		}
		return maxId;
	}
};




class Solution {
public:
	vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
		vector<vector<int>> adj(n);
		for (auto& edge : edges) {
			int x = edge[0] - 1;
			int y = edge[1] - 1;
			adj[x].emplace_back(y);
			adj[y].emplace_back(x);
		}
		function<int(int, int&, int&)> dfs = [&](int root, int& mask, int& diameter)->int {
			int first = 0, second = 0;
			mask &= ~(1 << root);
			for (int vertex : adj[root]) {
				if (mask & (1 << vertex)) {
					mask &= ~(1 << vertex);
					int distance = 1 + dfs(vertex, mask, diameter);
					if (distance > first) {
						second = first;
						first = distance;
					}
					else if (distance > second) {
						second = distance;
					}
				}
			}
			diameter = max(diameter, first + second);
			return first;
		};

		vector<int> ans(n - 1);
		for (int i = 1; i < (1 << n); i++) {
			int root = 32 - __builtin_clz(i) - 1;
			int mask = i;
			int diameter = 0;
			dfs(root, mask, diameter);
			if (mask == 0 && diameter > 0) {
				ans[diameter - 1]++;
			}
		}
		return ans;
	}
};
