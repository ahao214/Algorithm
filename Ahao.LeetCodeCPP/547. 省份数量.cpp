#include<vector>

using namespace std;


/*
547. ʡ������
�� n �����У�����һЩ�˴���������һЩû��������������� a ����� b ֱ���������ҳ��� b ����� c ֱ����������ô���� a ����� c ���������

ʡ�� ��һ��ֱ�ӻ��������ĳ��У����ڲ�������û�������ĳ��С�

����һ�� n x n �ľ��� isConnected ������ isConnected[i][j] = 1 ��ʾ�� i �����к͵� j ������ֱ���������� isConnected[i][j] = 0 ��ʾ���߲�ֱ��������

���ؾ����� ʡ�� ��������
*/
class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		for (int i = 0; i < n; i++)
		{
			p.push_back(i);
		}
		int res = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (isConnected[i][j] == 0) continue;
				if (find(i) != find(j))
				{
					p[find(i)] = find(j);
					res--;
				}
			}
		}
		return res;
	}
};
