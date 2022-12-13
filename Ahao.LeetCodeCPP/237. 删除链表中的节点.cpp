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
237. ɾ�������еĽڵ�
���дһ������������ ɾ����������ĳ���ض��ڵ� ��
����ƺ���ʱ��Ҫע�⣬���޷����������ͷ�ڵ� head ��
ֻ��ֱ�ӷ���Ҫ��ɾ���Ľڵ� ��

��Ŀ���ݱ�֤��Ҫɾ���Ľڵ� ����ĩβ�ڵ� ��
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
