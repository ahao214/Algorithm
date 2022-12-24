#include<vector>
#include <algorithm>

using namespace std;


/*
455. �ַ�����
��������һλ�ܰ��ļҳ�����Ҫ����ĺ�����һЩС���ɡ����ǣ�ÿ���������ֻ�ܸ�һ����ɡ�

��ÿ������ i������һ��θ��ֵ g[i]���������ú���������θ�ڵı��ɵ���С�ߴ磻����ÿ����� j������һ���ߴ� s[j] ����� s[j] >= g[i]�����ǿ��Խ�������� j ��������� i ��������ӻ�õ����㡣���Ŀ���Ǿ���������Խ�������ĺ��ӣ��������������ֵ��
*/
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int i = 0, j = 0, res = 0;
		for (int i = 0; i < g.size(); i++) {
			while (j < s.size() && s[j] < g[i])
				j++;
			if (j < s.size())
			{
				res++;
				j++;
			}
		}
		return res;
	}

	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int i = 0, j = 0;
		while (i < g.size() && j < s.size())
		{
			if (g[i] <= s[i])
				i++;
			j++;
		}
		return i;
	}
};
