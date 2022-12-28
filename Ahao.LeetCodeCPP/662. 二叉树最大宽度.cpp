#include<vector>
#include <queue>

using namespace std;


/*
662. 二叉树最大宽度
给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。

每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
*/
class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		queue<pair<TreeNode*, long long>> q;
		q.push({ root,0 });
		long long res = 0;
		while (!q.empty())
		{
			auto head = q.front();
			int size = q.size();
			pair<TreeNode*, long long> cur;
			for (int i = 0; i < size; i++)
			{
				cur = q.front();
				q.pop();
				TreeNode* curNode = cur.first;
				long long index = cur.second - head.second;
				if (curNode->left)
				{
					q.push({ curNode->left,2 * index });
				}
				if (curNode->right)
				{
					q.push({ curNode->right,2 * index + 1 });
				}
			}
			res = max(res, cur.second - head.second + 1);
		}
		return (int)res;
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