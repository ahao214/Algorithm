#include<vector>

using namespace std;


/*
120. ��������С·����
����һ�������� triangle ���ҳ��Զ����µ���С·���͡�

ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ����ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ���ߵ��� ��һ�����±� + 1 ��������㡣Ҳ����˵�������λ�ڵ�ǰ�е��±� i ����ô��һ�������ƶ�����һ�е��±� i �� i + 1 ��
*/
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int> f(triangle[n - 1].begin(), triangle[n - 1].end()), g(n);
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				g[j] = min(f[j], f[j + 1]) + triangle[i][j];
			}
			f = g;
		}
		return f[0];
	}
};