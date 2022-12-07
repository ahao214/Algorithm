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
297. �����������л��뷴���л�
���л��ǽ�һ�����ݽṹ���߶���ת��Ϊ�����ı���λ�Ĳ�����
�������Խ�ת��������ݴ洢��һ���ļ������ڴ��У�
ͬʱҲ����ͨ�����紫�䵽��һ���������������ȡ�෴��ʽ�ع��õ�ԭ���ݡ�

�����һ���㷨��ʵ�ֶ����������л��뷴���л���
���ﲻ�޶�������� / �����л��㷨ִ���߼���
��ֻ��Ҫ��֤һ�����������Ա����л�Ϊһ���ַ������ҽ�����ַ��������л�Ϊ
ԭʼ�����ṹ��

��ʾ: ���������ʽ�� LeetCode Ŀǰʹ�õķ�ʽһ�£�
��������� LeetCode ���л��������ĸ�ʽ���㲢�Ǳ����ȡ���ַ�ʽ��
��Ҳ���Բ��������ķ������������⡣
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