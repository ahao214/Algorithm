using namespace std;
#include<vector>
#include<string>

class Solution {
	vector<string> ans;
public:
	vector<string> generateParenthesis(int n) {
		dfs(0, 0, n, "");
		return ans;
	}

	//lc左括号数量 rc有括号数量
	void dfs(int lc, int rc, int n, string seq) {
		if (lc == n && rc == n) {
			ans.push_back(seq);
			return;
		}
		if (lc < n)
			dfs(lc + 1, rc, n, seq + "(");
		if (rc < n && lc > rc)
			dfs(lc, rc + 1, n, seq + ")");
	}
};

