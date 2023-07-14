#include<vector>
#include <functional>

using namespace std;


/*
979. 在二叉树中分配硬币

给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val 枚硬币，并且总共有 N 枚硬币。

在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。(移动可以是从父结点到子结点，或者从子结点移动到父结点。)。

返回使每个结点上只有一枚硬币所需的移动次数。
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
	vector<int> dfs(TreeNode* root)
	{
		if (!root) return { 0,0,0 };
		auto left = dfs(root->left), right = dfs(root->right);
		int x = left[0] + right[0] + 1, y = left[1] + right[1] + root->val;
		return { x,y,abs(x - y) + left[2] + right[2] };
	}

	int distributeCoins(TreeNode* root) {
		return dfs(root)[2];
	}
};



class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int move = 0;

        function<int(const TreeNode*)> dfs = [&](const TreeNode* root) -> int {
            int moveleft = 0;
            int moveright = 0;
            if (root == nullptr) {
                return 0;
            }
            if (root->left) {
                moveleft = dfs(root->left);
            }
            if (root->right) {
                moveright = dfs(root->right);
            }
            move += abs(moveleft) + abs(moveright);
            return moveleft + moveright + root->val - 1;
        };

        dfs(root);
        return move;
    }
};
