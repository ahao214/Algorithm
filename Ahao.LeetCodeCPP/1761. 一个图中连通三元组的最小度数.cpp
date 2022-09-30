#include<vector>
#include<unordered_set>


using namespace std;


/*
1761. һ��ͼ����ͨ��Ԫ�����С����
����һ������ͼ������ n ��ʾͼ�нڵ����Ŀ��edges �����ʾͼ�еıߣ����� edges[i] = [ui, vi] ����ʾ ui �� vi ֮����һ������ߡ�

һ�� ��ͨ��Ԫ�� ָ���� ���� �ڵ���ɵļ�������������֮�� ���� �бߡ�

��ͨ��Ԫ��Ķ��� ����������������ıߵ���Ŀ��һ�������������Ԫ���ڣ�����һ�����㲻�������Ԫ���ڡ�

���㷵��������ͨ��Ԫ���ж����� ��Сֵ �����ͼ��û����ͨ��Ԫ�飬��ô���� -1 ��
*/
class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		unordered_set<int> hash;
		vector<int> d(n + 1);
		for (auto& e : edges)
		{
			int a = e[0], b = e[1];
			if (a > b) swap(a, b);
			d[a]++, d[b]++;
			hash.insert(a * 1000 + b);
		}

		int res = INT_MAX;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (hash.count(i * 1000 + j))
					for (int k = j + 1; k <= n; k++)
						if (hash.count(i * 1000 + k) && hash.count(j * 1000 + k))
							res = min(res, d[i] + d[j] + d[k] - 6);
			}
		}

		if (res == INT_MAX)
			res = -1;
		return res;
	}
};