#include<vector>

using namespace std;



/*
offer 8 二叉树的下一个结点
*/


struct TreeLinkNode {
	int val;
	struct TreeLinkNode* left;
	struct TreeLinkNode* right;
	struct TreeLinkNode* next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};


class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode) {
		if (!pNode) return nullptr;
		TreeLinkNode* pNext = nullptr;
		if (pNode->right)
		{
			TreeLinkNode* pRight = pNode->right;
			while (pRight->left)
			{
				pRight = pRight->left;
			}
			pNext = pRight;
		}
		else if (pNode->next)
		{
			TreeLinkNode* pCur = pNode;
			while (pCur->next && pCur == pCur->next->right)
			{
				pCur = pCur->next;
			}
			pNext = pCur->next;
		}
		return pNext;
	}
};
