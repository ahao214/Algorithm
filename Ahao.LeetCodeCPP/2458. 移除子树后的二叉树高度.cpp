#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;



/*
2458. �Ƴ�������Ķ������߶�

����һ�� ������ �ĸ��ڵ� root �������� n ���ڵ㡣ÿ���ڵ㶼���Ա�����һ���� 1 �� n �һ�����ͬ��ֵ�������һ������Ϊ m ������ queries ��

�����������ִ�� m �� ���� �Ĳ�ѯ�����е� i ����ѯ����Ҫִ�����²�����

������ �Ƴ� �� queries[i] ��ֵ��Ϊ���ڵ����������Ŀ���ò���������֤ queries[i] �� ���ڸ��ڵ��ֵ��
����һ������Ϊ m ������ answer ������ answer[i] ��ִ�е� i ����ѯ�����ĸ߶ȡ�

ע�⣺

��ѯ֮���Ƕ����ģ�������ÿ����ѯִ�к�����ص��� ��ʼ ״̬��
���ĸ߶��ǴӸ�������ĳ���ڵ�� ���·���еı��� ��
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
	int depth[100005];
	int height[100005];
	unordered_map<int, vector<int>>d2h;
public:
	vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
		vector<int> res;
		dfs_height(root, 0);
		for (auto& [d, hs] : d2h) {
			sort(hs.rbegin(), hs.rend());
		}
		for (int node : queries) {
			int d = depth[node];
			int h = height[node];

			if (d2h[d].size() == 1)
				res.push_back(d - 1);
			else if (d2h[d][0] == h)
				res.push_back(d2h[d][1] + d);
			else if (d2h[d][0] != h)
				res.push_back(d2h[d][0] + d);
		}
		return res;
	}

	int dfs_height(TreeNode* node, int d) {
		if (node == nullptr) return -1;
		int h = max(dfs_height(node->left, d + 1), dfs_height(node->right, d + 1)) + 1;
		depth[node->val] = d;
		height[node->val] = h;
		d2h[d].push_back(h);
		return h;
	}
};