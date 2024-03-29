using namespace std;
#include<string>
#include<vector>


/*
14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		for (int i = 0; i < strs[0].length(); i++) {
			char c = strs[0][i];
			for (int j = 1; j < strs.size(); j++) {
				if (i == strs[j].length() || strs[j][i] != c) {
					return strs[0].substr(0, i);
				}
			}
		}
		return strs[0];
	}
};




class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		string res;
		for (int i = 0;; i++)
		{
			bool flag = false;
			string& first = strs[0];
			for (auto& now : strs)
			{
				if (i >= first.size() || i >= now.size() || first[i] != now[i])
				{
					flag = true;
					break;
				}
			}
			if (flag) break;
			res += first[i];
		}
		return res;
	}
};
