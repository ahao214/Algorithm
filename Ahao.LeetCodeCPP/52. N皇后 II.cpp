using namespace std;
#include<vector>
#include<string>


class Solution {
	/*
	52. N�ʺ� II
	n �ʺ����� �о�������ν� n ���ʺ������ n �� n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������

	����һ������ n ������ n �ʺ����� ��ͬ�Ľ��������������
	*/
	vector<bool> col, dg, udg;
	int ans = 0;
public:
	int totalNQueens(int n) {
		col = vector<bool>(n);
		dg = udg = vector<bool>(2 * n);
		dfs(0, n);
		return ans;
	}

	void dfs(int x, int n)
	{
		if (x == n)
		{
			ans++;
			return;
		}
		for (int y = 0; y < n; y++)
		{
			if (col[y] || udg[y - x + n] || dg[y + x]) continue;
			col[y] = udg[y - x + n] = dg[y + x] = true;
			dfs(x + 1, n);
			col[y] = udg[y - x + n] = dg[y + x] = false;
		}
	}
};
