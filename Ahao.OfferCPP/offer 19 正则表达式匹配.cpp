#include<vector>
#include<string>

using namespace std;


/*
offer 19 正则表达式匹配
*/
class Solution {
public:
	bool match(string str, string pattern) {
		if (str.size() == 0 && pattern.size() == 0)
		{
			return true;
		}
		if (str.size() != 0 && pattern.size() == 0)
		{
			return false;
		}
		return match(str, 0, pattern, 0);
	}


	bool match(string& s, int i, string& p, int j)
	{
		if (i == s.size() && j == p.size())
		{
			return true;
		}
		if (i < s.size() && j == p.size())
		{
			return false;
		}
		if (p[j + 1] == '*')
		{
			if (s[i] == p[j] || (p[j] == '.' && i < s.size()))
			{
				return match(s, i, p, j + 2) || match(s, i + 1, p, j + 2) || match(s, i + 1, p, j);
			}
			else
			{
				return match(s, i, p, j + 2);
			}
		}
		if (s[i] == p[j] || (p[j] == '.' && i < s.size()))
		{
			return match(s, i + 1, p, j + 1);
		}
		return false;
	}
};