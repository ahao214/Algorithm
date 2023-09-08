#include<vector>
#include <map>
#include <queue>

using namespace std;


/*
207. 课程表

你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。
先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi]
表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，
你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？
如果可以，返回 true ；否则，返回 false 。
*/
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		map<int, list<int>> adjList;
		vector<int> indegree(numCourses, 0);
		for (auto p : prerequisites)
		{
			int start = p[1], end = p[0];
			adjList[start].push_back(end);
			indegree[end]++;
		}
		queue<int> q;
		for (int i = 0; i < indegree.size(); i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
		int cnt = 0;
		while (!q.empty())
		{
			int course = q.front();
			q.pop();
			cnt++;
			for (int adj : adjList[course])
			{
				indegree[adj]--;
				if (indegree[adj] == 0)
					q.push(adj);
			}
		}
		return cnt == numCourses;
	}
};



class Solution {
private:
	vector<vector<int>> edges;
	vector<int> indeg;

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		indeg.resize(numCourses);
		for (const auto& info : prerequisites) {
			edges[info[1]].push_back(info[0]);
			++indeg[info[0]];
		}

		queue<int> q;
		for (int i = 0; i < numCourses; ++i) {
			if (indeg[i] == 0) {
				q.push(i);
			}
		}

		int visited = 0;
		while (!q.empty()) {
			++visited;
			int u = q.front();
			q.pop();
			for (int v : edges[u]) {
				--indeg[v];
				if (indeg[v] == 0) {
					q.push(v);
				}
			}
		}

		return visited == numCourses;
	}
};


class Solution {
private:
	vector<vector<int>> edges;
	vector<int> visited;
	bool valid = true;

public:
	void dfs(int u) {
		visited[u] = 1;
		for (int v : edges[u]) {
			if (visited[v] == 0) {
				dfs(v);
				if (!valid) {
					return;
				}
			}
			else if (visited[v] == 1) {
				valid = false;
				return;
			}
		}
		visited[u] = 2;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		visited.resize(numCourses);
		for (const auto& info : prerequisites) {
			edges[info[1]].push_back(info[0]);
		}
		for (int i = 0; i < numCourses && valid; ++i) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		return valid;
	}
};

