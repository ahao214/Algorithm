#include <algorithm>

using namespace std;


/*
offer 55 �����������
*/

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	int TreeDepth(TreeNode* pRoot) {
		if (!pRoot) return 0;
		return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
	}
};