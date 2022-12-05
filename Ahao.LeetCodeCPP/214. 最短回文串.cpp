#include<vector>
#include <string>

using namespace std;



/*
214. ��̻��Ĵ�
����һ���ַ��� s�������ͨ�����ַ���ǰ������ַ�����ת��Ϊ���Ĵ����ҵ������ؿ��������ַ�ʽת������̻��Ĵ���
*/
class Solution {
public:
	string shortestPalindrome(string s) {
		string raws = s;
		reverse(s.begin(), s.end());
		s = raws + '#' + s;
		int n = s.size();
		vector<int> nxt(n + 1, 0);
		for (int i = 2, j = 0; i <= n; i++)
		{
			while (j && s[j] != s[i - 1]) j = nxt[j];
			if (s[j] == s[i - 1]) j++;
			nxt[i] = j;
		}
		int res = nxt[n];
		string sup = raws.substr(res);
		reverse(sup.begin(), sup.end());
		return sup + raws;
	}
};
