using namespace std;

#include<string>

/*
5. ������Ӵ�
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
*/
class Solution {
public:
	string longestPalindrome(string s) {
		string res = "";
		for (int i = 0; i < s.length(); i++) {
			//�ַ�������Ϊ����
			int l = i - 1, r = i + 1;
			while (l >= 0 && r < s.length() && s[l] == s[r])
				l--, r++;
			if (res.length() < r - l - 1)
				res = s.substr(l + 1, r - l - 1);

			//�ַ�������Ϊż��
			l = i, r = i + 1;
			while (l >= 0 && r < s.length() && s[l] == s[r])
				l--, r++;
			if (res.length() < r - l - 1)
				res = s.substr(l + 1, r - l - 1);
		}
		return res;
	}
};
