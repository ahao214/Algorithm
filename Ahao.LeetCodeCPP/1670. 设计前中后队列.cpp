#include<vector>
#include<queue>

using namespace std;



/*
1670. 设计前中后队列
请你设计一个队列，支持在前，中，后三个位置的 push 和 pop 操作。

请你完成 FrontMiddleBack 类：

FrontMiddleBack() 初始化队列。
void pushFront(int val) 将 val 添加到队列的 最前面 。
void pushMiddle(int val) 将 val 添加到队列的 正中间 。
void pushBack(int val) 将 val 添加到队里的 最后面 。
int popFront() 将 最前面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
int popMiddle() 将 正中间 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
int popBack() 将 最后面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
请注意当有 两个 中间位置的时候，选择靠前面的位置进行操作。比方说：

将 6 添加到 [1, 2, 3, 4, 5] 的中间位置，结果数组为 [1, 2, 6, 3, 4, 5] 。
从 [1, 2, 3, 4, 5, 6] 的中间位置弹出元素，返回 3 ，数组变为 [1, 2, 4, 5, 6] 。
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