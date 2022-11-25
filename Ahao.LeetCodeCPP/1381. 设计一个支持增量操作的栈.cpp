#include<vector>

using namespace std;


/*
1381. ���һ��֧������������ջ
�������һ��֧������������ջ��

ʵ���Զ���ջ�� CustomStack ��

CustomStack(int maxSize)���� maxSize ��ʼ������maxSize ��ջ����������ɵ�Ԫ��������ջ�������� maxSize ֮����֧�� push ������
void push(int x)�����ջ��δ������ maxSize ���ͽ� x ��ӵ�ջ����
int pop()������ջ��Ԫ�أ�������ջ����ֵ����ջΪ��ʱ���� -1 ��
void inc(int k, int val)��ջ�׵� k ��Ԫ�ص�ֵ������ val �����ջ��Ԫ������С�� k ����ջ�е�����Ԫ�ض����� val ��
*/
class Solution {
public:
    vector<int> stk;
    int top;
    void CustomStack(int maxSize) {
        stk = vector<int>(maxSize);
        top = 0;
    }

    void push(int x) {
        if (top == stk.size()) return;
        stk[top++] = x;
    }

    int pop() {
        if (!top) return -1;
        return stk[--top];
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < top; i++)
            stk[i] += val;
    }
};

