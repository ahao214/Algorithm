#include<string>
#include <vector>

using namespace std;



/*
1781. 所有子字符串美丽值之和
一个字符串的 美丽值 定义为：出现频率最高字符与出现频率最低字符的出现次数之差。

比方说，"abaacc" 的美丽值为 3 - 1 = 2 。
给你一个字符串 s ，请你返回它所有子字符串的 美丽值 之和。
*/
class Solution {
public:
	int beautySum(string s) {
		int cnt[26];
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			memset(cnt, 0, sizeof cnt);
			for (int j = i; j < s.size(); j++)
			{
				cnt[s[j] - 'a']++;
				int minv = 1e8, maxv = -1;
				for (int k = 0; k < 26; k++)
				{
					if (cnt[k] > 0)
					{
						minv = min(minv, cnt[k]);
						maxv = max(maxv, cnt[k]);
					}
				}
				res += maxv - minv;
			}
		}
		return res;
	}
};



class Solution {
public:
	int beautySum(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			vector<int> cnt(26);
			int maxFreq = 0;
			for (int j = i; j < s.size(); j++) {
				cnt[s[j] - 'a']++;
				maxFreq = max(maxFreq, cnt[s[j] - 'a']);
				int minFreq = s.size();
				for (int k = 0; k < 26; k++) {
					if (cnt[k] > 0) {
						minFreq = min(minFreq, cnt[k]);
					}
				}
				res += maxFreq - minFreq;
			}
		}
		return res;
	}
};
