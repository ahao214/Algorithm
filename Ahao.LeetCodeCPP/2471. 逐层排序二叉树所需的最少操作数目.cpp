#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;



/*
2471. ��������������������ٲ�����Ŀ

����һ�� ֵ������ͬ �Ķ������ĸ��ڵ� root ��

��һ�������У������ѡ�� ͬһ�� �����������ڵ㣬�����������ڵ��ֵ��

����ÿһ�㰴 �ϸ����˳�� ������������ٲ�����Ŀ��

�ڵ�� ���� �Ǹýڵ�͸��ڵ�֮���·���ı�����
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
	vector<int>level[100005];
	int maxDepth;
public:
	int minimumOperations(TreeNode* root) {
		dfs(root, 0);
		int count = 0;
		for (int t = 0; t <= maxDepth; t++)
		{
			auto& nums = level[t];
			unordered_map<int, int>rank;
			auto sorted = nums;
			sort(sorted.begin(), sorted.end());
			for (int i = 0; i < sorted.size(); i++) {
				rank[sorted[i]] = i;
			}
			for (int i = 0; i < nums.size(); i++) {
				while (rank[nums[i]] != i) {
					swap(nums[i], nums[rank[nums[i]]]);
					count++;
				}
			}
		}
		return count;
	}

	void dfs(TreeNode* node, int depth)
	{
		if (node == nullptr)
			return;
		maxDepth = max(maxDepth, depth);
		level[depth].push_back(node->val);
		dfs(node->left, depth + 1);
		dfs(node->right, depth + 1);
	}
};