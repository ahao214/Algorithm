#include<vector>

using namespace std;



/*
1718. �����ֵ������Ŀ�������
����һ������ n �������ҵ���������������һ�����У�

���� 1 ��������ֻ����һ�Ρ�
2 �� n ֮��ÿ��������ǡ�ó������Ρ�
����ÿ�� 2 �� n ֮������� i ������ i ֮����ֵľ���ǡ��Ϊ i ��
�������������� a[i] �� a[j] ֮��� ���� �����Ƕ���Ϊ�����±����ֵ֮�� |j - i| ��

���㷵���������������� �ֵ������ �����С���Ŀ��֤�ڸ������������£�һ�����ڽ⡣

һ������ a ����Ϊ������ b �����߳�����ͬ���ֵ������������ǣ� a �� b �е�һ����һ�������ִ���a ���е����ֱ� b ���е����ִ󡣱ȷ�˵��[0,1,9,0] �� [0,1,5,6] �ֵ��������Ϊ��һ����ͬ��λ���ǵ��������֣��� 9 �� 5 ��
*/
class Solution {
public:
	int m;
	vector<int> st;
	vector<int> path;

	bool dfs(int u)
	{
		if (u == m * 2 - 1) return true;
		if (path[u]) return dfs(u + 1);
		for (int i = m; i > 1; i--)
		{
			if (!st[i] && u + i < m * 2 - 1 && !path[u + i])
			{
				path[u] = path[u + i] = i;
				st[i] = true;
				if (dfs(u + 1)) return true;
				st[i] = false;
				path[u] = path[u + i] = 0;
			}
		}
		if (!st[1])
		{
			st[1] = true;
			path[u] = 1;
			if (dfs(u + 1)) return true;
			path[u] = 0;
			st[1] = false;
		}
		return false;
	}

	vector<int> constructDistancedSequence(int n) {
		m = n;
		st.resize(m + 1, false);
		path.resize(m * 2 - 1);
		dfs(0);
		return path;
	}
};

