#include<vector>
#include <queue>

using namespace std;


/*
662. �����������
����һ������������дһ����������ȡ�����������ȡ����Ŀ�������в��е�����ȡ����������������������full binary tree���ṹ��ͬ����һЩ�ڵ�Ϊ�ա�

ÿһ��Ŀ�ȱ�����Ϊ�����˵㣨�ò���������ҵķǿսڵ㣬���˵���null�ڵ�Ҳ���볤�ȣ�֮��ĳ��ȡ�
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