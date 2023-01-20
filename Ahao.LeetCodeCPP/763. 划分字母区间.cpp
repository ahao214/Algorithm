#include<vector>
#include<string>

using namespace std;



/*
763. 划分字母区间

字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
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