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



/*
5. ������Ӵ�
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
*/
class Solution {
public:
	string longestPalindrome(string s) {
		int len = 0;
		string ans;
		for (int k = 0; k < s.size(); k++)
		{
			int i = k, j = k + 1;
			while (i >= 0 && j < s.size() && s[i] == s[j]) i--, j++;
			if (j - i - 1 > len)
			{
				len = j - i - 1;
				ans = s.substr(i + 1, len);
			}

			i = k - 1, j = k + 1;
			while (i >= 0 && j < s.size() && s[i] == s[j]) i--, j++;
			if (j - i - 1 > len)
			{
				len = j - i - 1;
				ans = s.substr(i + 1, len);
			}
		}
		return ans;
	}
};