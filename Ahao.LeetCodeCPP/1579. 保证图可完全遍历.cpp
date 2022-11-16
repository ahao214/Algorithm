#include<string>
#include<vector>


using namespace std;




/*
1579. ��֤ͼ����ȫ����
Alice �� Bob ����һ������ͼ�����а��� n ���ڵ�� 3  �����͵ıߣ�

���� 1��ֻ���� Alice ������
���� 2��ֻ���� Bob ������
���� 3��Alice �� Bob �����Ա�����
����һ������ edges ������ edges[i] = [typei, ui, vi] ��ʾ�ڵ� ui �� vi ֮���������Ϊ typei ��˫��ߡ������ڱ�֤ͼ���ܹ��� Alice�� Bob ��ȫ������ǰ���£��ҳ�����ɾ������������������κνڵ㿪ʼ��Alice �� Bob �����Ե������������ڵ㣬����Ϊͼ�ǿ�����ȫ�����ġ�

���ؿ���ɾ��������������� Alice �� Bob �޷���ȫ����ͼ���򷵻� -1
*/
class Solution {
public:
	vector<int> pa, pb;

	int find(vector<int>& p, int x)
	{
		if (p[x] != x) p[x] = find(p, p[x]);
		return p[x];
	}

	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		pa.resize(n + 1), pb.resize(n + 1);
		for (int i = 1; i <= n; i++) pa[i] = pb[i] = i;

		int res = 0, ca = n, cb = n;
		for (auto& e : edges)
		{
			if (e[0] == 3)
			{
				int x = e[1], y = e[2];
				int pax = find(pa, x), pay = find(pa, y);
				int pbx = find(pb, x), pby = find(pb, y);
				if (pax != pay)
				{
					pa[pax] = pay, ca--;
					pb[pbx] = pby, cb--;
				}
				else res++;
			}
		}

		for (auto& e : edges)
		{
			int t = e[0], x = e[1], y = e[2];
			if (t == 3) continue;
			if (t == 1)
			{
				int pax = find(pa, x), pay = find(pa, y);
				if (pax != pay)
				{
					pa[pax] = pay, ca--;
				}
				else res++;
			}
			else {
				int pbx = find(pb, x), pby = find(pb, y);
				if (pbx != pby)
				{
					pb[pbx] = pby, cb--;
				}
				else res++;
			}
		}

		if (ca > 1 || cb > 1) return -1;
		return res;
	}
};