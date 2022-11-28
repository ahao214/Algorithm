#include<vector>
#include<queue>

using namespace std;


/*
295. 数据流的中位数
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：
*/
class Solution {
public:
	priority_queue<int, vector<int>, greater<int>> up;
	priority_queue<int> down;

	void MedianFinder() {

	}

	void addNum(int num) {
		if (down.empty() || num >= down.top()) up.push(num);
		else
		{
			down.push(num);
			up.push(down.top());
			down.pop();
		}
		if (up.size() > down.size() + 1)
		{
			down.push(up.top());
			up.pop();
		}
	}

	double findMedian() {
		if (down.size() + up.size() & 1) return up.top();
		else
		{
			return (down.top() + up.top()) / 2.0;
		}
	}
};
