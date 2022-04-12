using namespace std;

#include<vector>
#include<string>

class Solution {
	/*
	3. 无重复字符的最长子串
	给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
	*/
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> pos(128, -1);
		int ans = 0;
		for (int i = 0, j = 0; i < s.length(); i++) {
			j = max(j, pos[s[i]] + 1);
			ans = max(ans, i - j + 1);
			pos[s[i]] = i;
		}
		return ans;
	}
};