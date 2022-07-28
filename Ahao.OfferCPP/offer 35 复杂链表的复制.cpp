#include<vector>

using namespace std;


/*
offer 35 复杂链表的复制
*/
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead) {
		//第一步：复制原链表中的节点，新节点连到原节点之后
		RandomListNode* p = pHead;
		while (p) {
			RandomListNode* pCloned = new RandomListNode(p->label);
			pCloned->next = p->next;
			p->next = pCloned;

			p = pCloned->next;
		}
		//第二步：复制random指针
		p = pHead;
		while (p) {
			RandomListNode* pCloned = p->next;
			if (p->random) {
				pCloned->random = p->random->next;
			}
			p = pCloned->next;
		}

		//第三步：拆分链表(奇偶数节点)
		p = pHead;
		RandomListNode* pClonedHead = nullptr;
		RandomListNode* pClonedNode = nullptr;
		if (p) {
			pClonedHead = p->next;
			pClonedNode = p->next;
			p->next = pClonedNode->next;
			p = p->next;
		}

		while (p) {
			pClonedNode->next = p->next;
			pClonedNode = p->next;
			p->next = pClonedNode->next;
			p = p->next;
		}
		return pClonedHead;

	}
};


class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};