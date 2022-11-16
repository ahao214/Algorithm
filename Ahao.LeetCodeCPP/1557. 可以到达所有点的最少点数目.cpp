#include<vector>

using namespace std;


/*
1557. ���Ե������е�����ٵ���Ŀ
����һ�� �����޻�ͼ �� n ���ڵ���Ϊ 0 �� n-1 ���Լ�һ�������� edges ������ edges[i] = [fromi, toi] ��ʾһ���ӵ�  fromi ���� toi ������ߡ�

�ҵ���С�ĵ㼯ʹ�ô���Щ������ܵ���ͼ�����е㡣��Ŀ��֤�������Ψһ��

�����������˳�򷵻���Щ�ڵ��š�
*/
class Solution {
public:
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
		vector<int> res;
		vector<int> d(n);
		for (auto e : edges)
		{
			int a = e[0], b = e[1];
			d[b]++;
		}
		for (int i = 0; i < n; i++)
		{
			if (!d[i])
				res.push_back(i);
		}
		return res;
	}
};