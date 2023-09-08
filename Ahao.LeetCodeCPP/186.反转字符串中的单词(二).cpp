#include<vector>

using namespace std;


/*
186.反转字符串中的单词(二)

*/

class Solution {
public:
	void reverseWords(vector<char>& s) {
		int n = s.size();
		//对每个单词进行反转
		for (int i = 0, j = 0; i <= n; i++)
		{
			if (i == n || s[i] == ' ')
			{
				reverse(s.begin() + j, s.begin() + i);
				j = i + 1;
			}
		}
		reverse(s.begin(), s.end());
	}
}