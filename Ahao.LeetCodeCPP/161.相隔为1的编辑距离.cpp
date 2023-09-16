#include<vector>
#include<string>

using namespace std;



/*
161.Ïà¸ôÎª1µÄ±à¼­¾àÀë
*/

class Solution {
public:
	bool isOneEditDistance(string s, string t) {
		int n = s.length(), m = t.length();
		if (n < m) return isOneEditDistance(t, s);
		if (n - m > 1)
			return false;

		for (int i = 0; i < m; i++)
		{
			if (s[i] != t[i])
			{
				if (n == m)
					return s.substr(i + 1) == t.substr(i + 1);
				else
					return s.substr(i + 1) == t.substr(i);
			}
		}
		return n == m + 1;
	}
};
