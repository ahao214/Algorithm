#include<vector>
#include <map>
#include <queue>

using namespace std;


/*
207. �γ̱�

�����ѧ�ڱ���ѡ�� numCourses �ſγ̣���Ϊ 0 �� numCourses - 1 ��

��ѡ��ĳЩ�γ�֮ǰ��ҪһЩ���޿γ̡�
���޿γ̰����� prerequisites ���������� prerequisites[i] = [ai, bi]
��ʾ���Ҫѧϰ�γ� ai �� ���� ��ѧϰ�γ�  bi ��

���磬���޿γ̶� [0, 1] ��ʾ����Ҫѧϰ�γ� 0 ��
����Ҫ����ɿγ� 1 ��
�����ж��Ƿ����������пγ̵�ѧϰ��
������ԣ����� true �����򣬷��� false ��
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

