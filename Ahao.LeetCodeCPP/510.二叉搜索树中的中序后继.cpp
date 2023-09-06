#include<vector>

using namespace std;



/*
510.二叉搜索树中的中序后继

*/
//class Solution {
//public:
//	Node* inorderSuccessor(Node* node) {
//		if (node->right)
//		{
//			node = node->right;
//			while (node->left)
//			{
//				node = node->parent;
//			}
//			return node;
//		}
//
//		while (node->parent && node->parent->right == node)
//			node = node->parent;
//		return node->parent;
//	}
//};


