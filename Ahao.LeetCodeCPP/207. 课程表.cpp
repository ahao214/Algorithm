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