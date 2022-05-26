using namespace std;
#include<vector>
#include<string>

class Solution {
	/*
	51. N �ʺ�
	n �ʺ����� �о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������

	����һ������ n ���������в�ͬ�� n �ʺ����� �Ľ��������

	ÿһ�ֽⷨ����һ����ͬ�� n �ʺ����� �����ӷ��÷������÷����� 'Q' �� '.' �ֱ�����˻ʺ�Ϳ�λ��
	*/
	//col:�� dg:�Խ��� udg:б�Խ���
	vector<bool> col, dg, udg;
	vector<string> path;
	vector<vector<string>> ans;
public:
	vector<vector<string>> solveNQueens(int n) {
		col = vector<bool>(n);
		dg = udg = vector<bool>(2 * n);
		path = vector<string>(n, string(n, '.'));
		dfs(0, n);
		return ans;
	}

	void dfs(int x, int n)
	{
		if (x == n)
		{
			ans.push_back(path);
			return;
		}
		for (int y = 0; y < n; y++)
		{
			if (col[y] || udg[y - x + n] || dg[y + x]) continue;
			col[y] = udg[y - x + n] = dg[y + x] = true;
			path[x][y] = 'Q';
			dfs(x + 1, n);
			path[x][y] = '.';
			col[y] = udg[y - x + n] = dg[y + x] = false;
		}
	}

};
