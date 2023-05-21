#include<vector>

using namespace std;

/*
1080. ����Ҷ·���ϵĲ���ڵ�

����������ĸ��ڵ� root ��һ������ limit ������ͬʱɾ���������� ����ڵ� �����������ն������ĸ��ڵ㡣

����ͨ���ڵ� node ��ÿ�ֿ��ܵ� ����-Ҷ�� ·����ֵ���ܺ�ȫ��С�ڸ����� limit����ýڵ㱻��֮Ϊ ����ڵ� ����Ҫ��ɾ����

Ҷ�ӽڵ㣬����û���ӽڵ�Ľڵ㡣
*/


class Solution {
public:
	bool checkSufficientLeaf(TreeNode* node, int sum, int limit) {
		if (!node) {
			return false;
		}
		if (node->left == nullptr && node->right == nullptr) {
			return node->val + sum >= limit;
		}
		bool haveSufficientLeft = checkSufficientLeaf(node->left, sum + node->val, limit);
		bool haveSufficientRight = checkSufficientLeaf(node->right, sum + node->val, limit);
		if (!haveSufficientLeft) {
			node->left = nullptr;
		}
		if (!haveSufficientRight) {
			node->right = nullptr;
		}
		return haveSufficientLeft || haveSufficientRight;
	}

	TreeNode* sufficientSubset(TreeNode* root, int limit) {
		bool haveSufficient = checkSufficientLeaf(root, 0, limit);
		return haveSufficient ? root : nullptr;
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
