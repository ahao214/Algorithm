using namespace std;
#include<vector>
#include<string>


class Solution {
	vector<string> ans;
	string strs[10] = {
		"","","abc","def",
		"ghi","jkl","mno",
		"pqrs","tuv","wxyz"
	};
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return ans;
		dfs(digits, 0, "");
		return ans;
	}

	//DFS方法
	void dfs(string& digits, int idx, string combine) {
		if (idx == digits.length()) {
			ans.push_back(combine);
			return;
		}
		string s = strs[digits[idx] - '0'];
		for (int i = 0; i < s.length(); i++) {
			combine.push_back(s[i]);
			dfs(digits, idx + 1, combine);
			combine.pop_back();
		}
	}
};



/*
17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
class Solution {
public:
	string chars[8] = {
		"abc","def",
		"ghi","jkl","mno",
		"pqrs","tuv","wxyz"
	};
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return vector<string>();

		vector<string> state(1, "");
		for (auto u : digits)
		{
			vector<string> now;
			for (auto c : chars[u - '2'])
			{
				for (auto s : state)
					now.push_back(s + c);
			}
			state = now;
		}
		return state;
	}
};
