#include<vector>
#include <unordered_map>

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




class Solution {
public:
    int getf(vector<int>& f, int x) {
        if (f[x] == x) {
            return x;
        }
        int newf = getf(f, f[x]);
        f[x] = newf;
        return newf;
    }

    void add(vector<int>& f, int x, int y) {
        int fx = getf(f, x);
        int fy = getf(f, y);
        f[fx] = fy;
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int tot = n / 2;
        vector<int> f(tot, 0);
        for (int i = 0; i < tot; i++) {
            f[i] = i;
        }

        for (int i = 0; i < n; i += 2) {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            add(f, l, r);
        }

        unordered_map<int, int> m;
        for (int i = 0; i < tot; i++) {
            int fx = getf(f, i);
            m[fx]++;
        }

        int ret = 0;
        for (const auto& [f, sz] : m) {
            ret += sz - 1;
        }
        return ret;
    }
};
