#include<vector>
#include <unordered_map>

using namespace std;



/*
1171. ��������ɾȥ�ܺ�ֵΪ��������ڵ�

����һ�������ͷ�ڵ� head�������д���룬����ɾȥ�������� �ܺ� ֵΪ 0 �������ڵ���ɵ����У�ֱ������������������Ϊֹ��

ɾ����Ϻ����㷵�����ս�������ͷ�ڵ㡣



����Է����κ�������ĿҪ��Ĵ𰸡�

��ע�⣬����ʾ���е��������У����Ƕ� ListNode �������л��ı�ʾ����
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix = 0;
        unordered_map<int, ListNode*> seen;
        for (ListNode* node = dummy; node; node = node->next) {
            prefix += node->val;
            seen[prefix] = node;
        }
        prefix = 0;
        for (ListNode* node = dummy; node; node = node->next) {
            prefix += node->val;
            node->next = seen[prefix]->next;
        }
        return dummy->next;
    }
};
