using namespace std;

#include<vector>
#include<string>
#include <unordered_map>
#include <queue>

class Solution {
	/*
	49. 字母异位词分组
	给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

	字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
	*/
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