#include<vector>

using namespace std;


/*
1723. ������й��������ʱ��
����һ���������� jobs ������ jobs[i] ����ɵ� i ���Ҫ���ѵ�ʱ�䡣

���㽫��Щ��������� k λ���ˡ����й�����Ӧ�÷�������ˣ���ÿ���ֻ�ܷ����һλ���ˡ����˵� ����ʱ�� ����ɷ�������ǵ����й�������ʱ����ܺ͡��������һ����ѵĹ������䷽����ʹ���˵� �����ʱ�� ���� ��С�� ��

���ط��䷽���о����� ��С �� �����ʱ�� ��
*/
class Solution {
public:
	vector<int> s;
	vector<int> jobss;
	int ans = 1e9;

	void dfs(int a, int b, int c)
	{
		if (c > ans)
			return;
		if (a == jobss.size())
		{
			ans = c;
			return;
		}
		for (int i = 0; i < b; i++)
		{
			s[i] += jobss[a];
			dfs(a + 1, b, max(c, s[i]));
			s[i] -= jobss[a];
		}
		if (b < s.size())
		{
			s[b] = jobss[a];
			dfs(a + 1, b + 1, max(c, s[b]));
			s[b] = 0;
		}

	}

	int minimumTimeRequired(vector<int>& jobs, int k) {
		jobss = jobs, s.resize(k);
		dfs(0, 0, 0);
		return ans;
	}
};
