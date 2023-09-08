#include<vector>
#include<stack>

using namespace std;


/*
173. ����������������

ʵ��һ��������������������BSTIterator ����ʾһ�����������������������BST���ĵ�������
BSTIterator(TreeNode root) ��ʼ�� BSTIterator ���һ������BST �ĸ��ڵ� root ����Ϊ���캯����һ���ָ�����ָ��Ӧ��ʼ��Ϊһ���������� BST �е����֣��Ҹ�����С�� BST �е��κ�Ԫ�ء�
boolean hasNext() �����ָ���Ҳ�����������֣��򷵻� true �����򷵻� false ��
int next()��ָ�������ƶ���Ȼ�󷵻�ָ�봦�����֡�
ע�⣬ָ���ʼ��Ϊһ���������� BST �е����֣����Զ� next() ���״ε��ý����� BST �е���СԪ�ء�

����Լ��� next() ����������Ч�ģ�Ҳ����˵�������� next() ʱ��BST ��������������ٴ���һ����һ�����֡�
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
	stack<TreeNode*> stk;
	void BSTIterator(TreeNode* root) {
		while (root)
		{
			stk.push(root);
			root = root->left;
		}
	}

	int next() {
		auto t = stk.top();
		stk.pop();
		for (auto p = t->right; p; p = p->left)
		{
			stk.push(p);
		}
		return t->val;
	}

	bool hasNext() {
		return !stk.empty();
	}
};



/*
173. ����������������

ʵ��һ��������������������BSTIterator ����ʾһ�����������������������BST��
�ĵ�������
BSTIterator(TreeNode root) ��ʼ�� BSTIterator ���һ������
BST �ĸ��ڵ� root ����Ϊ���캯����һ���ָ�����
ָ��Ӧ��ʼ��Ϊһ���������� BST �е����֣��Ҹ�����С�� BST �е��κ�Ԫ�ء�
boolean hasNext() �����ָ���Ҳ�����������֣��򷵻� true �����򷵻� false ��
int next()��ָ�������ƶ���Ȼ�󷵻�ָ�봦�����֡�
ע�⣬ָ���ʼ��Ϊһ���������� BST �е����֣����Զ� next() ���״ε��ý�����
BST �е���СԪ�ء�

����Լ��� next() ����������Ч�ģ�Ҳ����˵�������� next() ʱ��
BST ��������������ٴ���һ����һ�����֡�
*/
class BSTIterator {
public:
	stack<TreeNode*> stk;
	BSTIterator(TreeNode* root) {
		while (root)
		{
			stk.push(root);
			root = root->left;
		}
	}

	int next() {
		auto p = stk.top();
		stk.pop();
		int res = p->val;
		p = p->right;
		while (p)
		{
			stk.push(p);
			p = p->left;
		}
		return res;
	}

	bool hasNext() {
		return !stk.empty();
	}
};




class BSTIterator {
	stack<TreeNode*> stk;
	TreeNode* cur;
public:
	BSTIterator(TreeNode* root) {
		cur = root;
	}

	int next() {
		while (cur)
		{
			stk.push(cur);
			cur = cur->left;
		}
		cur = stk.top();
		stk.pop();
		int res = cur->val;
		cur = cur->right;
		return res;
	}

	bool hasNext() {
		return cur || !stk.empty();
	}
};