#include<vector>
#include<unordered_map>

using namespace std;



/*
138. 复制带随机指针的链表
*/
//时间O(N) 空间O(N)

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


class Solution {
public:
	Node* copyRandomList(Node* head) {
		unordered_map<Node*, Node*> h;
		for (Node* cur = head; cur; cur = cur->next)
		{
			h[cur] = new Node(cur->val);
		}
		for (Node* cur = head; cur; cur = cur->next)
		{
			if (cur->next)
				h[cur]->next = h[cur->next];
			if (cur->random)
				h[cur]->random = h[cur->random];
		}
		return h[head];
	}
};