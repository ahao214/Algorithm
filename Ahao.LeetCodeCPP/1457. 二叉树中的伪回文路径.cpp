#include<vector>
#include<unordered_map>


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
1457. �������е�α����·��
����һ�ö�������ÿ���ڵ��ֵΪ 1 �� 9 �����ǳƶ������е�һ��·���� ��α���ġ��ģ��������㣺·�����������нڵ�ֵ�������У�����һ���������С�

���㷵�شӸ���Ҷ�ӽڵ������·���� α���� ·������Ŀ��
*/
class Solution {
public:
	unordered_map<int, int> cnt;

	int pseudoPalindromicPaths(TreeNode* root) {
		cnt[root->val] ++;
		if (!root->left && !root->right)
		{
			int t = 0;
			for (auto item : cnt)
			{
				if (item.second % 2)
					t++;
			}
			cnt[root->val]--;
			return t <= 1;
		}
		int res = 0;
		if (root->left) res += pseudoPalindromicPaths(root->left);
		if (root->right) res += pseudoPalindromicPaths(root->right);

		cnt[root->val]--;
		return res;
	}
};


