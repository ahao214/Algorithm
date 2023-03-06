#include<vector>

using namespace std;


/*
765. ����ǣ��

n �����������������е� 2n ����λ�ϣ���Ҫǣ���Է����֡�

�˺���λ��һ���������� row ��ʾ������ row[i] �����ڵ� i ����λ�ϵ��˵� ID�������ǰ�˳���ţ���һ���� (0, 1)���ڶ����� (2, 3)���Դ����ƣ����һ���� (2n-2, 2n-1)��

���� ���ٽ�����λ�Ĵ������Ա�ÿ�����¿��Բ�������һ�� ÿ�ν�����ѡ���������ˣ�������վ����������λ��
*/
class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x)
			p[x] = find(p[x]);
		return p[x];
	}
	int minSwapsCouples(vector<int>& row) {
		int n = row.size() / 2;
		for (int i = 0; i < n; i++)
			p.push_back(i);
		int cnt = n;
		for (int i = 0; i < n * 2; i += 2)
		{
			int a = row[i] / 2, b = row[i + 1] / 2;
			if (find(a) != find(b))
			{
				p[find(a)] = find(b);
				cnt--;
			}
		}
		return n - cnt;
	}
};