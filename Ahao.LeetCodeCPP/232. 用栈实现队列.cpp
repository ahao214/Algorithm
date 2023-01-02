#include<vector>
#include<stack>

using namespace std;

/*
232. ��ջʵ�ֶ���
�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����

ʵ�� MyQueue �ࣺ

void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
int peek() ���ض��п�ͷ��Ԫ��
boolean empty() �������Ϊ�գ����� true �����򣬷��� false
˵����

�� ֻ�� ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ�� push to top, peek/pop from top, size, �� is empty �����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
*/

class MyQueue {
public:
	stack<int> stIn;
	stack<int> stOut;
	MyQueue() {

	}

	void push(int x) {
		stIn.push(x);
	}

	int pop() {
		if (stOut.empty()) {
			while (!stIn.empty()) {
				stOut.push(stIn.top());
				stIn.pop();
			}
		}
		int result = stOut.top();
		stOut.pop();
		return result;
	}

	int peek() {
		int res = this->pop();
		stOut.push(res);
		return res;
	}

	bool empty() {
		return stIn.empty() && stOut.empty();
	}
};

