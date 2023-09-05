#include<vector>
#include <queue>

using namespace std;

/*
108. ����������ת��Ϊ����������

����һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ�� �߶�ƽ�� ������������

�߶�ƽ�� ��������һ�����㡸ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ���Ķ�������
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
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return build(nums, 0, nums.size() - 1);
	}

	TreeNode* build(vector<int>& nums, int left, int right)
	{
		if (left > right) return NULL;
		int mid = (left + right) >> 1;
		auto root = new TreeNode(nums[mid]);
		root->left = build(nums, left, mid - 1);
		root->right = build(nums, mid + 1, right);
		return root;
	}
};