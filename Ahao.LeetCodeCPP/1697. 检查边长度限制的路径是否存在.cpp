#include<vector>
#include <algorithm>

using namespace std;



/*
1697. ���߳������Ƶ�·���Ƿ����
����һ�� n ������ɵ�����ͼ�߼� edgeList ������ edgeList[i] = [ui, vi, disi] ��ʾ�� ui �͵� vi ֮����һ������Ϊ disi �ıߡ���ע�⣬������֮������� ����һ���� ��

����һ����ѯ����queries ������ queries[j] = [pj, qj, limitj] ����������Ƕ���ÿ����ѯ queries[j] ���ж��Ƿ���ڴ� pj �� qj ��·����������·���ϵ�ÿһ���߶� �ϸ�С�� limitj ��

���㷵��һ�� �������� answer ������ answer.length == queries.length ���� queries[j] �Ĳ�ѯ���Ϊ true ʱ�� answer �� j ��ֵΪ true ������Ϊ false ��
*/
const int N = 100010;
struct Node {
	int a, b, c, d;
	bool operator< (const Node& t) const {
		return c < t.c;
	}
}e[N], q[N];

class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x)
			p[x] = find(p[x]);
		return p[x];
	}

	vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
		int m = edgeList.size(), k = queries.size();

		for (int i = 0; i < m; i++)
			e[i] = { edgeList[i][0],edgeList[i][1],edgeList[i][2] };
		for (int i = 0; i < k; i++)
			q[i] = { queries[i][0],queries[i][1],queries[i][2],i };

		sort(e, e + m), sort(q, q + k);

		p.resize(n);
		for (int i = 0; i < n; i++) p[i] = i;
		vector<bool> res(k);

		for (int i = 0, j = 0; i < k; i++)
		{
			while (j < m && e[j].c < q[i].c)
			{
				int a = e[j].a, b = e[j].b;
				p[find(a)] = find(b);
				j++;
			}
			res[q[i].d] = find(q[i].a) == find(q[i].b);
		}
		return res;
	}
};