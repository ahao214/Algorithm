#include<vector>

using namespace std;


/*
1627. ����ֵ��ͼ��ͨ��
�� n �����У���Ŵ� 1 �� n �����Ϊ x �� y ����������ֱ����ͨ��ǰ���ǣ� x �� y �Ĺ������У�������һ�� �ϸ���� ĳ����ֵ threshold ������ʽ��˵������������� z �������������������������� x �� y �ĳ���֮����һ����·��

x % z == 0
y % z == 0
z > threshold
������������ n �� threshold ���Լ�һ������ѯ���飬�����ж�ÿ����ѯ queries[i] = [ai, bi] ָ��ĳ��� ai �� bi �Ƿ���ͨ����������֮���Ƿ����һ��·������

�������� answer ������answer.length == queries.length ������� i ����ѯ��ָ��ĳ��� ai �� bi ��ͨ���� answer[i] Ϊ true ���������ͨ���� answer[i] Ϊ false ��
*/
class Solution {
	vector<int> Father;
	int FindFather(int x)
	{
		if (Father[x] != x)
			Father[x] = FindFather(Father[x]);
		return Father[x];
	}

	void Union(int x, int y)
	{
		x = Father[x];
		y = Father[y];
		if (x < y) Father[y] = x;
		else Father[x] = y;
	}
public:
	vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
		Father.resize(n + 1);
		for (int i = 1; i <= n; i++)
			Father[i] = i;
		for (int k = threshold + 1; k <= n; k++)
		{
			for (int x = 2 * k; x <= n; x += k)
			{
				if (FindFather(x) != FindFather(k))
					Union(x, k);
			}
		}
		vector<bool> res;
		for (auto query : queries)
			res.push_back(FindFather(query[0]) == FindFather(query[1]));
		return res;
	}
};




class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
		p.resize(n + 1);
		for (int i = 1; i <= n; i++) p[i] = i;
		for (int d = threshold + 1; d <= n; d++)
			for (int i = d * 2; i <= n; i += d)
				p[find(d)] = p[find(i)];

		vector<bool> res;
		for (auto& q : queries)
			res.push_back(find(q[0]) == find(q[1]));

		return res;
	}
};