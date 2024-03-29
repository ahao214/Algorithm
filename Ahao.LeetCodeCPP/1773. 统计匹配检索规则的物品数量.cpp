#include<vector>
#include<string>
#include<unordered_map>

using namespace std;



/*
1773. 统计匹配检索规则的物品数量
给你一个数组 items ，其中 items[i] = [typei, colori, namei] ，描述第 i 件物品的类型、颜色以及名称。

另给你一条由两个字符串 ruleKey 和 ruleValue 表示的检索规则。

如果第 i 件物品能满足下述条件之一，则认为该物品与给定的检索规则 匹配 ：

ruleKey == "type" 且 ruleValue == typei 。
ruleKey == "color" 且 ruleValue == colori 。
ruleKey == "name" 且 ruleValue == namei 。
统计并返回 匹配检索规则的物品数量 。
*/
class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int res = 0;
		for (auto& s : items)
		{
			if (ruleKey == "type" && s[0] == ruleValue) res++;
			else if (ruleKey == "color" && s[1] == ruleValue) res++;
			else if (ruleKey == "name" && s[2] == ruleValue) res++;
		}
		return res;
	}
};


class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		unordered_map<string, int> dictionary = { {"type", 0}, {"color", 1}, {"name", 2} };
		int res = 0, index = dictionary[ruleKey];
		for (auto&& item : items) {
			if (item[index] == ruleValue) {
				res++;
			}
		}
		return res;
	}
};
