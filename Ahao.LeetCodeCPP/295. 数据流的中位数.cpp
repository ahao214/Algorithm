#include<vector>
#include<queue>

using namespace std;


/*
295. ����������λ��
��λ���������б��м����������б�����ż������λ�������м���������ƽ��ֵ��

���磬

[2,3,4] ����λ���� 3

[2,3] ����λ���� (2 + 3) / 2 = 2.5

���һ��֧���������ֲ��������ݽṹ��

void addNum(int num) - �������������һ�����������ݽṹ�С�
double findMedian() - ����Ŀǰ����Ԫ�ص���λ����
ʾ����
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
