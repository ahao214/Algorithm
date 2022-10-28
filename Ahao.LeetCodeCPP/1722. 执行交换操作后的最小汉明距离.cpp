#include<vector>

using namespace std;


/*
1722. ִ�н������������С��������
���������������� source �� target �����ȶ��� n ������һ������ allowedSwaps ������ÿ�� allowedSwaps[i] = [ai, bi] ��ʾ����Խ������� source ���±�Ϊ ai �� bi���±�� 0 ��ʼ��������Ԫ�ء�ע�⣬����԰� ���� ˳�� ��� ����һ���ض��±�ָ���Ԫ�ء�

��ͬ���ȵ��������� source �� target ��� �������� ��Ԫ�ز�ͬ���±���������ʽ�ϣ���ֵ�������� source[i] != target[i] ���±�� 0 ��ʼ�����±� i��0 <= i <= n-1����������

�ڶ����� source ִ�� ���� �����Ľ��������󣬷��� source �� target ��� ��С�������� ��
*/
class Solution {
public:
	vector<int> p;

	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
		int n = source.size();
		for (int i = 0; i < n; i++) p.push_back(i);
		for (auto& t : allowedSwaps) p[find(t[0])] = find(t[1]);

		vector<unordered_multiset<int>> hash(n);
		for (int i = 0; i < n; i++)
		{
			hash[find(i)].insert(source[i]);
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			auto& h = hash[find(i)];
			if (h.count(target[i])) h.erase(h.find(target[i]));
			else res++;
		}
		return res;
	}
};

