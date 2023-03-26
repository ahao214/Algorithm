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


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

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




/*
652. Ѱ���ظ�������
*/
class Solution {
public:
	unordered_map<string, int> ids;
	int cnt = 0;
	unordered_map<int, int> hash;
	vector<TreeNode*> ans;
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs(root);
		return ans;
	}

	int dfs(TreeNode* root)
	{
		if (!root) return 0;
		int left = dfs(root->left);
		int right = dfs(root->right);
		string key = to_string(root->val) + ' ' + to_string(left) + ' ' + to_string(right);
		if (ids.count(key) == 0) ids[key] = ++cnt;
		int id = ids[key];
		if (++hash[id] == 2) ans.push_back(root);
		return id;
	}
};
