#include<vector>
#include <string>

using namespace std;


/*
520. ¼ì²â´óÐ´×ÖÄ¸
*/
class Solution {
public:
	bool check(char c)
	{
		return c >= 'A' && c <= 'Z';
	}

	bool detectCapitalUse(string word) {
		int s = 0;
		for (auto c : word)
		{
			if (check(c))
				s++;
		}
		return s == word.size() || !s || s == 1 && check(word[0]);
	}
};
