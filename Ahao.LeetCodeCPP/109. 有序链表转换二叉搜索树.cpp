#include<vector>
#include <queue>

using namespace std;

/*
109. ��������ת������������

����һ���������ͷ�ڵ�  head �����е�Ԫ�� ���������� ������ת��Ϊ�߶�ƽ��Ķ�����������

�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ���� 1��
*/


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};


class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		int n = 0;
		for (auto p = head; p; p = p->next)
			n++;
		if (n == 1) return new TreeNode(head->val);
		auto cur = head;
		for (int i = 0; i < n / 2 - 1; i++)
			cur = cur->next;
		auto root = new TreeNode(cur->next->val);
		root->right = sortedListToBST(cur->next->next);
		cur->next = NULL;
		root->left = sortedListToBST(head);
		return root;
	}
};