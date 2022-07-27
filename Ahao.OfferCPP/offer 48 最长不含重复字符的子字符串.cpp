#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


/*
offer 48 最长不含重复字符的子字符串
*/
class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param s string字符串
	 * @return int整型
	 */
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) return 0;
		unordered_map<char, int> um;
		int ans = -1;
		int l = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			auto itor = um.find(s[i]);
			if (itor == um.end())
			{
				um.insert(make_pair(s[i], i));
				l++;
			}
			else if (i - um[s[i]] > l)
			{
				um[s[i]] = i;
				l++;
			}
			else
			{
				l = i - um[s[i]];
				um[s[i]] = i;
			}
			ans = max(l, ans);
		}
		return ans;
	}
};
