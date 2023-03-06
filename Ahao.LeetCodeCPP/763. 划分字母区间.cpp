#include<vector>
#include<string>
#include <unordered_map>

using namespace std;



/*
763. 划分字母区间

给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。

注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

返回一个表示每个字符串片段的长度的列表。
*/
class Solution {
public:
	vector<int> partitionLabels(string s) {
		vector<int> last(26, 0);
		for (int i = 0; i < s.size(); i++)
		{
			last[s[i] - 'a'] = i;
		}
		vector<int> res;
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			end = max(end, last[s[i] - 'a']);
			if (end == i)
			{
				res.push_back(end - start + 1);
				start = end + 1;
			}
		}
		return res;
	}
};





class Solution {
public:
	vector<int> partitionLabels(string s) {
		unordered_map<char, int> last;
		for (int i = 0; i < s.size(); i++)
			last[s[i]] = i;
		vector<int> res;
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			end = max(end, last[s[i]]);
			if (i == end)
			{
				res.push_back(end - start + 1);
				start = end = i + 1;
			}
		}
		return res;
	}
};
