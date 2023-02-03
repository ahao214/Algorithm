#include<vector>

using namespace std;

/*
924. �������ٶ�������Ĵ���

������һ���� n ���ڵ���ɵ����磬�� n �� n ���ڽӾ���ͼ graph ��ʾ���ڽڵ������У��� graph[i][j] = 1 ʱ����ʾ�ڵ� i �ܹ�ֱ�����ӵ���һ���ڵ� j��

һЩ�ڵ� initial ��������������Ⱦ��ֻҪ�����ڵ�ֱ�����ӣ�����������һ���ڵ��ܵ���������ĸ�Ⱦ����ô�����ڵ㶼�������������Ⱦ�����ֶ�������Ĵ�����������ֱ��û�и���Ľڵ���Ա����ַ�ʽ��Ⱦ��

���� M(initial) ���ڶ������ֹͣ����֮�����������и�Ⱦ������������սڵ�����

����� initial ���Ƴ�ĳһ�ڵ��ܹ���С�� M(initial)�� ���ظýڵ㡣����ж���ڵ������������ͷ���������С�Ľڵ㡣

��ע�⣬���ĳ���ڵ��Ѵ��ܸ�Ⱦ�ڵ���б� initial ��ɾ�������Ժ����п������������������ܵ���Ⱦ��
*/
class Solution {
public:
	vector<int> p, s, c;
	int find(int x)
	{
		if (p[x] != x)
			p[x] = find(p[x]);
		return p[x];
	}
	int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
		int n = graph.size();
		for (int i = 0; i < n; i++)
		{
			p.push_back(i);
			s.push_back(1);
			c.push_back(0);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[i][j] && find(i) != find(j))
				{
					s[find(i)] += s[find(j)];
					p[find(j)] = find(i);
				}
			}
		}

		for (auto x : initial) c[find(x)]++;
		int res = -1, rp = INT_MAX;
		for (auto x : initial)
		{
			if (res == -1) rp = min(rp, x);
			if (c[find(x)] == 1)
			{
				if (res < s[find(x)])
				{
					res = s[find(x)];
					rp = x;
				}
				else if (res == s[find(x)])
				{
					rp = min(rp, x);
				}
			}
		}
		return rp;
	}
};