#include<vector>
#include<string>
#include <unordered_map>

using namespace std;



/*
159.至多包含两个不同字符串的最长子串
*/

class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int ans = 0;
		unordered_map<char, int> h;
		for (int i = 0, j = 0; i < s.length(); i++)
		{
			h[s[i]]++;
			while (h.size() > 2)
			{
				h[s[j]]--;
				if (!h[s[j]])
					h.erase(s[j]);
				j++;
			}
			ans = max(ans, i - j + 1);
		}
		return ans;
	}
};