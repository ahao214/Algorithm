using namespace std;

#include<vector>
#include<string>
#include <unordered_map>
#include <queue>

/*
49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> record;
		for (int i = 0; i < strs.size(); i++)
		{
			string key = strs[i];
			sort(key.begin(), key.end());
			record[key].push_back(strs[i]);
		}
		vector<vector<string>> ans;
		for (auto it = record.begin(); it != record.end(); it++)
		{
			ans.push_back(it->second);
		}
		return ans;
	}
};



/*
49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> dict;
		for (auto& str : strs)
		{
			string key = str;
			sort(key.begin(), key.end());
			dict[key].push_back(str);
		}

		vector<vector<string>> res;
		for (auto i = dict.begin(); i != dict.end(); i++)
		{
			res.push_back(i->second);
		}
		return res;
	}
};