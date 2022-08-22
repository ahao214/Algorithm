#include<vector>
#include<string>

using namespace std;


/*
1857. ����ͼ�������ɫֵ
����һ�� ����ͼ �������� n ���ڵ�� m ���ߡ��ڵ��Ŵ� 0 �� n - 1 ��

����һ���ַ��� colors ������ colors[i] ��СдӢ����ĸ����ʾͼ�е� i ���ڵ�� ��ɫ ���±�� 0 ��ʼ����ͬʱ����һ����ά���� edges ������ edges[j] = [aj, bj] ��ʾ�ӽڵ� aj ���ڵ� bj ��һ�� ����� ��

ͼ��һ����Ч ·�� ��һ�������� x1 -> x2 -> x3 -> ... -> xk ���������� 1 <= i < k ���� xi �� xi+1 ��ͼ����һ������ߡ�·���� ��ɫֵ ��·���� ���ִ������ ��ɫ�Ľڵ���Ŀ��

���㷵�ظ���ͼ����Ч·������� �����ɫֵ �����ͼ�к��л����뷵�� -1 ��
*/
class Solution {
public:
	int largestPathValue(string colors, vector<vector<int>>& edges) {
		int n = colors.size();
		vector<vector<int>>g(n), f(n, vector<int>(26));
		vector<int> d(n), p;
		for (auto& e : edges)
		{
			int a = e[0], b = e[1];
			g[a].push_back(b);
			d[b]++;
		}
		queue<int> q;
		for (int i = 0; i < n; i++)
		{
			if (!d[i])
				q.push(i);
		}

		while (q.size())
		{
			auto t = q.front();
			q.pop();
			p.push_back(t);

			for (int j : g[t])
				if (!--d[j])
					q.push(j);
		}

		if (p.size() < n) return -1;
		int res = 0;
		for (int i : p)
		{
			int c = colors[i] - 'a';
			f[i][c] = max(f[i][c], 1);
			for (int j = 0; j < 26; j++)
			{
				for (int k : g[i])
				{
					int t = 0;
					if (colors[k] - 'a' == j) t = 1;
					f[k][j] = max(f[k][j], f[i][j] + t);
				}
				res = max(res, f[i][j]);
			}
		}
		return res;
	}
};