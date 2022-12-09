#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


/*
652. Ѱ���ظ�������
����һ�ö����� root�����������ظ���������

����ͬһ����ظ���������ֻ��Ҫ������������һ�õĸ���㼴�ɡ�

���������������ͬ�Ľṹ����ͬ�Ľ��ֵ�����������ظ��ġ�
*/
class Solution {
public:
	unordered_map<string, int> hash;
	vector<TreeNode*> ans;
	string dfs(TreeNode* u)
	{
		if (!u) return "NULL";
		string left = dfs(u->left);
		string right = dfs(u->right);
		string s = to_string(u->val) + ',' + left + ',' + right;
		if (++hash[s] == 2) ans.push_back(u);
		return s;
	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs(root);
		return ans;
	}
};