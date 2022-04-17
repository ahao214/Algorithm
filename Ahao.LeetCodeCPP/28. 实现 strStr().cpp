using namespace std;
#include<string>;
#include<vector>;

class Solution {
	/*
	28. ʵ�� strStr()
	ʵ�� strStr() ������

	���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle
	�ַ������ֵĵ�һ��λ�ã��±�� 0 ��ʼ����
	��������ڣ��򷵻�  -1
	*/
public:
	int strStr(string haystack, string needle) {
		int n = haystack.length(), m = needle.length();
		if (m == 0) return 0;

		haystack.insert(haystack.begin(), ' ');
		needle.insert(needle.begin(), ' ');

		vector<int> next(m + 1);
		for (int i = 2, j = 0; i <= m; i++) {
			while (j > 0 && needle[i] != needle[j + 1])
				j = next[j];
			if (needle[i] == needle[j + 1])
				j++;
			next[i] = j;
		}

		for (int i = 1, j = 0; i <= n; i++) {
			while (j > 0 && haystack[i] != needle[j + 1])
				j = next[j];
			if (haystack[i] == needle[j + 1])
				j++;
			if (j == m)
				return i - m;
		}
		return -1;
	}
};
