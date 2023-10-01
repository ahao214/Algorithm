#include<string>
#include<unordered_set>
#include<vector>


using namespace std;




/*
140. 单词拆分 II
*/
//时间O(N) 空间O(1)
class Solution {
	unordered_set<string> st;
	vector<string> ans;
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		st = unordered_set<string>(wordDict.begin(), wordDict.end());
		dfs(s, 0, "");
		return ans;
	}

	void dfs(string& s, int idx, string cur)
	{
		if (idx == s.length())
		{
			ans.push_back(cur);
			return;
		}
		for (int i = idx; i < s.length(); i++)
		{
			string word = s.substr(idx, i - idx + 1);
			if (st.count(word))
			{
				dfs(s, i + 1, !cur.empty() ? cur + " " + word : word);
			}
		}
	}
};
