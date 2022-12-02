#include<vector>
#include <string>

using namespace std;


/*
125. ��֤���Ĵ�
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
*/
class Solution {
public:
	bool check(char c)
	{
		return c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
	}
	bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			while (i < j && !check(s[i])) i++;
			while (i < j && !check(s[j])) j--;
			if (s[i] != s[j] && s[i] != (s[j] ^ 32)) return false;
		}
		return true;
	}
};

