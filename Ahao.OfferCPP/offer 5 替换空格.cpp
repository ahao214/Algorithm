#include<vector>
#include<string>

using namespace std;


/*
offer 5 Ìæ»»¿Õ¸ñ
*/
class Solution {
public:
	string replaceSpace(string s) {
		if (s.empty()) return s;
		int count = 0;
		for (auto i : s)
		{
			if (i == ' ')
				count++;
		}
		s.resize(s.length() + count * 2, 0);
		for (int i = s.length() - 1; i >= 0; --i)
		{
			if (s[i] != ' ')
			{
				s[i + count * 2] = s[i];
			}
			if (s[i] == ' ')
			{
				count--;
				s[i + count * 2] = '%';
				s[i + count * 2 + 1] = '2';
				s[i + count * 2 + 2] = '0';
			}
		}
		return s;
	}
};