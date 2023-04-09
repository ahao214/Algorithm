#include<vector>
#include <stack>

using namespace std;

/*
1019. �����е���һ������ڵ�

����һ������Ϊ n ������ head

�����б��е�ÿ���ڵ㣬������һ�� ����ڵ� ��ֵ��Ҳ����˵������ÿ���ڵ㣬�ҵ����Աߵĵ�һ���ڵ��ֵ������ڵ��ֵ �ϸ���� ����ֵ��

����һ���������� answer ������ answer[i] �ǵ� i ���ڵ�( ��1��ʼ )����һ������Ľڵ��ֵ������� i ���ڵ�û����һ������Ľڵ㣬���� answer[i] = 0 ��
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