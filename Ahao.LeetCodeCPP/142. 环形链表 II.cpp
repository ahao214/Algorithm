#include<vector>
#include <unordered_set>

using namespace std;


/*
142. 环形链表 II

给定一个链表的头节点  head ，返回链表开始入环的第一个节点。
如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，
则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos
来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，
仅仅是为了标识链表的实际情况。

不允许修改 链表。
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		auto fast = head, slow = head;
		while (slow)
		{
			fast = fast->next;
			slow = slow->next;
			if (slow) slow = slow->next;
			else break;

			if (fast == slow)
			{
				slow = head;
				while (slow != fast)
				{
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		return NULL;
	}
};



class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		unordered_set<ListNode*> visited;
		while (head != nullptr) {
			if (visited.count(head)) {
				return head;
			}
			visited.insert(head);
			head = head->next;
		}
		return nullptr;
	}
};





class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* slow = head, * fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				slow = head;
				while (slow != fast)
				{
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		return nullptr;
	}
};