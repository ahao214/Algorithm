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

	//DFS����
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
17. �绰�������ĸ���
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
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
