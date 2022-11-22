#include<vector>
#include <algorithm>

using namespace std;


/*
1489. �ҵ���С��������Ĺؼ��ߺ�α�ؼ���
����һ�� n ����Ĵ�Ȩ������ͨͼ���ڵ���Ϊ 0 �� n-1 ��ͬʱ����һ������ edges ������ edges[i] = [fromi, toi, weighti] ��ʾ�� fromi �� toi �ڵ�֮����һ����Ȩ����ߡ���С������ (MST) �Ǹ���ͼ�бߵ�һ���Ӽ��������������нڵ���û�л���������Щ�ߵ�Ȩֵ����С��

�����ҵ�����ͼ����С�����������йؼ��ߺ�α�ؼ��ߡ������ͼ��ɾȥĳ���ߣ��ᵼ����С��������Ȩֵ�����ӣ���ô���Ǿ�˵����һ���ؼ��ߡ�α�ؼ������ǿ��ܻ������ĳЩ��С�������е����������������С�������еıߡ�

��ע�⣬����Էֱ�������˳�򷵻عؼ��ߵ��±��α�ؼ��ߵ��±ꡣ
*/
class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	int work1(int n, vector<vector<int>>& edges, int k) {
		//���õ�k����
		for (int i = 0; i < n; i++) p[i] = i;

		int res = 0, cnt = 0;
		for (auto& e : edges)
		{
			if (e[3] == k) continue;
			int a = e[1], b = e[2], w = e[0];
			if (find(a) != find(b)) {
				res += w;
				p[find(a)] = find(b);
				cnt--;
			}
		}
		if (cnt > 1) res = INT_MAX;
		return res;
	}


	int work2(int n, vector<vector<int>>& edges, int k) {
		//�����õ�k����
		for (int i = 0; i < n; i++) p[i] = i;

		int res = 0, cnt = 0;

		for (auto& e : edges)
		{
			if (e[3] == k) {
				int a = e[1], b = e[2], w = e[0];
				if (find(a) != find(b)) {
					res += w;
					p[find(a)] = find(b);
					cnt--;
				}
				break;
			}
		}

		for (auto& e : edges)
		{
			if (e[3] == k) continue;
			int a = e[1], b = e[2], w = e[0];
			if (find(a) != find(b)) {
				res += w;
				p[find(a)] = find(b);
				cnt--;
			}
		}
		if (cnt > 1) res = INT_MAX;
		return res;
	}

	vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
		int m = edges.size();
		for (int i = 0; i < m; i++)
		{
			auto& e = edges[i];
			swap(e[0], e[2]);
			e.push_back(i);
		}
		p = vector<int>(n);

		sort(edges.begin(), edges.end());
		int cost = work1(n, edges, -1);
		vector<vector<int>> res(2);
		for (int k = 0; k < m; k++)
		{
			if (work1(n, edges, k) != cost) res[0].push_back(k);
			else if (work2(n, edges, k) == cost) res[1].push_back(k);
		}
		return res;
	}
};