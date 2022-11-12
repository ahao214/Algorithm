#include<vector>

using namespace std;



/*
2181. �ϲ���֮��Ľڵ�
����һ�������ͷ�ڵ� head ������������� 0 �ָ�����һ��������������� ���� �� ĩβ �Ľڵ㶼���� Node.val == 0 ��

����ÿ�������ڵ� 0 �����㽫����֮������нڵ�ϲ���һ���ڵ㣬��ֵ�������Ѻϲ��ڵ��ֵ֮�͡�Ȼ������ 0 �Ƴ����޸ĺ������Ӧ�ú����κ� 0 ��

�����޸ĺ������ͷ�ڵ� head ��
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
	ListNode* mergeNodes(ListNode* head) {
		ListNode* now = head;
		while (now != NULL) {
			if (now->val == 0) {
				now = now->next;
				continue;
			}
			ListNode* nxt = now->next;
			if (nxt->val != 0) {
				now->val += nxt->val;
				now->next = nxt->next;
			}
			else {
				now = now->next;
			}
		}
		now = head->next;
		while (now != NULL) {
			ListNode* nxt = now->next;
			if (nxt->val == 0)
				now->next = nxt->next;
			now = now->next;
		}
		return head->next;
	}


public:
	ListNode* mergeNodes(ListNode* head) {
		head = head->next;
		int sum = 0;
		vector<int> num;
		while (head != NULL)
		{
			if (head->val == 0)
			{
				num.push_back(sum);
				sum = 0;
			}
			else
			{
				sum += head->val;
			}
			head = head->next;
		}

		ListNode* ret, * cur;
		ret = cur = new ListNode(num[0]);
		int m = num.size();
		for (int i = 1; i < m; i++)
		{
			ListNode* node = new ListNode(num[i]);
			cur->next = node;
			cur = cur->next;
		}
		return ret;
	}
};