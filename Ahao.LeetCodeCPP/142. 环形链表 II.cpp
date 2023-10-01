#include<vector>
#include <unordered_set>

using namespace std;


/*
142. �������� II

����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣
��������޻����򷵻� null��

�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε��
�������д��ڻ���
Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos
����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
��� pos �� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�
������Ϊ�˱�ʶ�����ʵ�������

�������޸� ����
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