#include<vector>
#include <unordered_set>
#include <functional>

using namespace std;


/*
1110. ɾ�����

�����������ĸ��ڵ� root������ÿ���ڵ㶼��һ����ͬ��ֵ��

����ڵ�ֵ�� to_delete �г��֣����ǾͰѸýڵ������ɾȥ�����õ�һ��ɭ�֣�һЩ���ཻ�������ɵļ��ϣ���

����ɭ���е�ÿ����������԰�����˳����֯�𰸡�
*/

class Solution {
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
		vector<TreeNode*> roots;

		function<TreeNode* (TreeNode*, bool)> dfs = [&](TreeNode* node, bool is_root) -> TreeNode* {
			if (node == nullptr) {
				return nullptr;
			}
			bool deleted = to_delete_set.count(node->val) ? true : false;
			node->left = dfs(node->left, deleted);
			node->right = dfs(node->right, deleted);
			if (deleted) {
				return nullptr;
			}
			else {
				if (is_root) {
					roots.emplace_back(node);
				}
				return node;
			}
		};

		dfs(root, true);
		return roots;
	}
};


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};