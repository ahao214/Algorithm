#include<vector>
#include <string>

using namespace std;




/*
680. ��֤�����ַ��� ��
����һ���ǿ��ַ��� s�����ɾ��һ���ַ����ж��Ƿ��ܳ�Ϊ�����ַ�����
*/
class Solution {
public:
	bool isValid(string s, int i, int j)
	{
		while (i < j)
		{
			if (s[i] != s[j])
			{
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

	bool validPalindrome(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			if (s[i] != s[j])
			{
				return (isValid(s, i, j - 1) || isValid(s, i + 1, j));
			}
			i++;
			j--;
		}
		return true;
	}
};
