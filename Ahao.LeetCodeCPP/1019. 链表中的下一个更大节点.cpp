#include<vector>
#include <stack>

using namespace std;

/*
1019. 链表中的下一个更大节点

给定一个长度为 n 的链表 head

对于列表中的每个节点，查找下一个 更大节点 的值。也就是说，对于每个节点，找到它旁边的第一个节点的值，这个节点的值 严格大于 它的值。

返回一个整数数组 answer ，其中 answer[i] 是第 i 个节点( 从1开始 )的下一个更大的节点的值。如果第 i 个节点没有下一个更大的节点，设置 answer[i] = 0 。
*/


class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> ans;
		stack<pair<int, int>> s;

		ListNode* cur = head;
		int idx = -1;
		while (cur) {
			++idx;
			ans.push_back(0);
			while (!s.empty() && s.top().first < cur->val) {
				ans[s.top().second] = cur->val;
				s.pop();
			}
			s.emplace(cur->val, idx);
			cur = cur->next;
		}

		return ans;
	}
};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};