#include<vector>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
1367. �������е��б�
����һ���� root Ϊ���Ķ�������һ�� head Ϊ��һ���ڵ������

����ڶ������У�����һ��һֱ���µ�·������ÿ�������ֵǡ��һһ
��Ӧ�� head Ϊ�׵�������ÿ���ڵ��ֵ����ô���㷵�� True ��
���򷵻� False ��

һֱ���µ�·������˼�ǣ�������ĳ���ڵ㿪ʼ��һֱ�������µ�·����
*/
class Solution {
public:
	bool isSubPath(ListNode* head, TreeNode* root) {
		if (dfs(head, root)) return true;

		if (!root) return false;
		//ö�����
		return isSubPath(head, root->left) || isSubPath(head, root->right);
	}

	bool dfs(ListNode* cur, TreeNode* root)
	{
		if (!cur) return true;
		if (!root) return false;

		if (cur->val != root->val) return false;

		return dfs(cur->next, root->left) || dfs(cur->next, root->right);
	}
};
