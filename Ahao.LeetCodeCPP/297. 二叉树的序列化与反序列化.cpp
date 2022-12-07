#include<vector>
#include <string>

using namespace std;



struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};




/*
297. 二叉树的序列化与反序列化
序列化是将一个数据结构或者对象转换为连续的比特位的操作，
进而可以将转换后的数据存储在一个文件或者内存中，
同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。
这里不限定你的序列 / 反序列化算法执行逻辑，
你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为
原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，
详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，
你也可以采用其他的方法解决这个问题。
*/
class Solution {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		dfs1(root, res);
		return res;
	}

	void dfs1(TreeNode* root, string& res)
	{
		if (!root)
		{
			res += "#,";
			return;
		}
		res += to_string(root->val) + ',';
		dfs1(root->left, res);
		dfs1(root->right, res);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int u = 0;
		return dfs2(data, u);
	}

	TreeNode* dfs2(string& data, int& u)
	{
		if (data[u] == '#')
		{
			u += 2;
			return NULL;
		}
		int t = 0;
		bool is_mins = false;
		if (data[u] == '-')
		{
			is_mins = true;
			u++;
		}
		while (data[u] != ',')
		{
			t = t * 10 + data[u] - '0';
			u++;
		}
		u++;
		if (is_mins)
			t = -t;
		auto root = new TreeNode(t);
		root->left = dfs2(data, u);
		root->right = dfs2(data, u);
		return root;
	}
};