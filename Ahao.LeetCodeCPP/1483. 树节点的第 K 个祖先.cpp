#include<vector>
#include <queue>

using namespace std;


/*
1483. ���ڵ�ĵ� K ������
����һ������������ n ���ڵ㣬���� 0 �� n-1 ��š����Ը��ڵ��������ʽ���������� parent[i] �ǽڵ� i �ĸ��ڵ㡣���ĸ��ڵ��Ǳ��Ϊ 0 �Ľڵ㡣

������Ʋ�ʵ�� getKthAncestor(int node, int k) �������������ؽڵ� node �ĵ� k �����Ƚڵ㡣������������������Ƚڵ㣬���� -1 ��

���ڵ�ĵ� k �����Ƚڵ��ǴӸýڵ㵽���ڵ�·���ϵĵ� k ���ڵ㡣
*/
class Solution {
public:

	vector<vector<int>> f;
	vector<vector<int>> g;
	void TreeAncestor(int n, vector<int>& parent) {
		f = vector<vector<int>>(n, vector<int>(16, -1));
		g = vector<vector<int>>(n);
		int root = 0;
		for (int i = 0; i < n; i++)
		{
			if (parent[i] == -1) root = i;
			else
				g[parent[i]].push_back(i);
		}
		queue<int> q;
		q.push(root);
		while (q.size())
		{
			int x = q.front();
			q.pop();
			for (auto y : g[x])
			{
				f[y][0] = x;
				for (int k = 1; k < 16; k++)
				{
					if (f[y][k - 1] != -1)
						f[y][k] = f[f[y][k - 1]][k - 1];
				}
				q.push(y);
			}
		}
	}

	int getKthAncestor(int node, int k) {
		for (int i = 0; i < 16; i++)
		{
			if (k >> i & 1)
			{
				node = f[node][i];
				if (node == -1)
					return node;
			}
		}
		return node;
	}
};




/*
1483. ���ڵ�ĵ� K ������

����һ������������ n ���ڵ㣬���� 0 �� n-1 ��š����Ը��ڵ��������ʽ���������� parent[i] �ǽڵ� i �ĸ��ڵ㡣���ĸ��ڵ��Ǳ��Ϊ 0 �Ľڵ㡣

���ڵ�ĵ� k �����Ƚڵ��ǴӸýڵ㵽���ڵ�·���ϵĵ� k ���ڵ㡣

ʵ�� TreeAncestor �ࣺ

TreeAncestor��int n�� int[] parent�� �����͸������еĽڵ�����ʼ������
getKthAncestor(int node, int k) ���ؽڵ� node �ĵ� k �����Ƚڵ㡣������������������Ƚڵ㣬���� -1 ��
*/
class TreeAncestor {
	vector<vector<int>>p;
public:
	TreeAncestor(int n, vector<int>& parent)
	{
		vector<vector<int>>p(n, vector<int>(20, -1));  // p[i][j] means the 2^j-th ancestor for node i
		for (int i = 0; i < n; i++)
			p[i][0] = parent[i];

		for (int j = 1; j < 20; j++)
			for (int i = 0; i < n; i++)
			{
				if (p[i][j - 1] != -1)
					p[i][j] = p[p[i][j - 1]][j - 1];
			}
		this->p = p;
	}

	int getKthAncestor(int node, int k)
	{
		for (int i = 0; i < 20; i++)
		{
			if ((k >> i) & 1)
			{
				node = p[node][i];
				if (node == -1) break;
			}
		}
		return node;
	}
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
