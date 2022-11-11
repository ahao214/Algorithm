#include<vector>
#include<queue>

using namespace std;



/*
1670. ���ǰ�к����
�������һ�����У�֧����ǰ���У�������λ�õ� push �� pop ������

������� FrontMiddleBack �ࣺ

FrontMiddleBack() ��ʼ�����С�
void pushFront(int val) �� val ��ӵ����е� ��ǰ�� ��
void pushMiddle(int val) �� val ��ӵ����е� ���м� ��
void pushBack(int val) �� val ��ӵ������ ����� ��
int popFront() �� ��ǰ�� ��Ԫ�شӶ�����ɾ��������ֵ�����ɾ��֮ǰ����Ϊ�գ���ô���� -1 ��
int popMiddle() �� ���м� ��Ԫ�شӶ�����ɾ��������ֵ�����ɾ��֮ǰ����Ϊ�գ���ô���� -1 ��
int popBack() �� ����� ��Ԫ�شӶ�����ɾ��������ֵ�����ɾ��֮ǰ����Ϊ�գ���ô���� -1 ��
��ע�⵱�� ���� �м�λ�õ�ʱ��ѡ��ǰ���λ�ý��в������ȷ�˵��

�� 6 ��ӵ� [1, 2, 3, 4, 5] ���м�λ�ã��������Ϊ [1, 2, 6, 3, 4, 5] ��
�� [1, 2, 3, 4, 5, 6] ���м�λ�õ���Ԫ�أ����� 3 �������Ϊ [1, 2, 4, 5, 6] ��
*/
class Solution {
public:
	deque<int> left, right;

	/*FrontMiddleBackQueue() {

	}*/

	void adjust() {
		while (left.size() > right.size())
		{
			right.push_front(left.back());
			left.pop_back();
		}
		while (right.size() > left.size() + 1)
		{
			left.push_back(right.front());
			right.pop_front();
		}
	}

	void pushFront(int val) {
		left.push_front(val);
		adjust();
	}

	void pushMiddle(int val) {
		left.push_back(val);
		adjust();
	}

	void pushBack(int val) {
		right.push_back(val);
		adjust();
	}

	int popFront() {
		if (right.empty())
			return -1;
		int res;
		if (left.size()) res = left.front(), left.pop_front();
		else res = right.front(), right.pop_front();
		adjust();
		return res;
	}

	int popMiddle() {
		if (right.empty())
			return -1;
		int res;
		if (left.size() == right.size()) res = left.back(), left.pop_back();
		else res = right.front(), right.pop_front();
		adjust();
		return res;
	}

	int popBack() {
		if (right.empty())
			return -1;
		int res = right.back();
		right.pop_back();
		adjust();
		return res;
	}
};