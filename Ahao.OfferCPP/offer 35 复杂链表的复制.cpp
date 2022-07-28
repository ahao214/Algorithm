#include<vector>

using namespace std;


/*
offer 35 ��������ĸ���
*/
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead) {
		//��һ��������ԭ�����еĽڵ㣬�½ڵ�����ԭ�ڵ�֮��
		RandomListNode* p = pHead;
		while (p) {
			RandomListNode* pCloned = new RandomListNode(p->label);
			pCloned->next = p->next;
			p->next = pCloned;

			p = pCloned->next;
		}
		//�ڶ���������randomָ��
		p = pHead;
		while (p) {
			RandomListNode* pCloned = p->next;
			if (p->random) {
				pCloned->random = p->random->next;
			}
			p = pCloned->next;
		}

		//���������������(��ż���ڵ�)
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