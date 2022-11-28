#include<vector>

using namespace std;


/*
684. ��������
�����Կ�����һ����ͨ�� �޻� �� ���� ͼ��

������һ�� n ���ڵ� (�ڵ�ֵ 1��n) ���������һ���ߺ��ͼ����ӵıߵ�������������� 1 �� n �м䣬���������ӵı߲����������Ѵ��ڵıߡ�ͼ����Ϣ��¼�ڳ���Ϊ n �Ķ�ά���� edges ��edges[i] = [ai, bi] ��ʾͼ���� ai �� bi ֮�����һ���ߡ�

���ҳ�һ������ɾȥ�ıߣ�ɾ�����ʹ��ʣ�ಿ����һ������ n ���ڵ����������ж���𰸣��򷵻����� edges �������ֵıߡ�
*/
class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		for (int i = 0; i <= n; i++)
		{
			p.push_back(i);
		}
		for (auto e : edges)
		{
			int a = e[0], b = e[1];
			if (find(a) == find(b)) return { a,b };
			p[find(a)] = find(b);
		}
		return { -1,-1 };
	}
};