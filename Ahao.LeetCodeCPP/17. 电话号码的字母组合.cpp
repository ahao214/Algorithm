using namespace std;
#include<vector>
#include<string>

//LC-17
class Solution {
	/*
	17. �绰�������ĸ���
	����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�

	�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
	*/
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

