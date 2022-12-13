#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};


/*
237. 删除链表中的节点
请编写一个函数，用于 删除单链表中某个特定节点 。
在设计函数时需要注意，你无法访问链表的头节点 head ，
只能直接访问要被删除的节点 。

题目数据保证需要删除的节点 不是末尾节点 。
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
