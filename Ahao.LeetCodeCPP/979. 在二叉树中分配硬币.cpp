#include<vector>
#include <functional>

using namespace std;


/*
979. �ڶ������з���Ӳ��

����һ���� N �����Ķ������ĸ���� root�����е�ÿ������϶���Ӧ�� node.val öӲ�ң������ܹ��� N öӲ�ҡ�

��һ���ƶ��У����ǿ���ѡ���������ڵĽ�㣬Ȼ��һöӲ�Ҵ�����һ������ƶ�����һ����㡣(�ƶ������ǴӸ���㵽�ӽ�㣬���ߴ��ӽ���ƶ�������㡣)��

����ʹÿ�������ֻ��һöӲ��������ƶ�������
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
