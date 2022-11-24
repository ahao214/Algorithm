#include<vector>
#include <string>

using namespace std;


/*
1392. �����ǰ׺
������ǰ׺������ԭ�ַ����м��� �ǿ� ǰ׺Ҳ�Ǻ�׺��������ԭ�ַ����������ַ�����

����һ���ַ��� s�����㷵������ �����ǰ׺��

������������������ǰ׺���򷵻�һ�����ַ�����
*/
class Solution {
public:
	string longestPrefix(string s) {
		int n = s.size();
		s = ' ' + s;
		vector<int> res(n + 1);

		for (int i = 2, j = 0; i <= n; i++)
		{
			while (j && s[i] != s[j + 1])
				j = res[j];
			if (s[i] == s[j + 1]) j++;
			res[i] = j;
		}
		return s.substr(1, res[n]);
	}
};