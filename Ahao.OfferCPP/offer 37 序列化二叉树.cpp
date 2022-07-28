#include<vector>
#include<string>

using namespace std;

/*
offer 37 ÐòÁÐ»¯¶þ²æÊ÷
*/
class Solution {
public:
	char* Serialize(TreeNode* root) {
		string str;
		SerializeCore(root, str);
		char* ans = new char[str.size() + 1];
		str.copy(ans, str.size());
		return ans;
	}

	void SerializeCore(TreeNode* root, string& str) {
		if (!root)
		{
			str += "#,";
			return;
		}
		else
		{
			str += to_string(root->val) + ",";
		}
		SerializeCore(root->left, str);
		SerializeCore(root->right, str);
	}

	TreeNode* Deserialize(char* str) {
		string s = str;
		TreeNode* root = nullptr;
		DeserializeCore(&root, s);
		return root;
	}

	void DeserializeCore(TreeNode** root, string& s)
	{
		if (s.empty()) return;
		if (s[0] == '#')
		{
			s = s.substr(2);
		}
		else
		{
			string tmp;
			int i = 0;
			for (i; i < s.size(); ++i)
			{
				if (s[i] == ',')
				{
					tmp = s.substr(0, i);
					break;
				}
			}
			int n = atoi(tmp.c_str());
			*root = new TreeNode(n);
			s = s.substr(i + 1);
			DeserializeCore(&((*root)->left), s);
			DeserializeCore(&((*root)->right), s);
		}
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