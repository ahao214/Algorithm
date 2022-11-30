#include<unordered_map>
#include<stack>

using namespace std;

/*
895. ���Ƶ��ջ
���һ�����ƶ�ջ�����ݽṹ����Ԫ�������ջ�����Ӷ�ջ�е�������Ƶ����ߵ�Ԫ�ء�

ʵ�� FreqStack ��:

FreqStack() ����һ���յĶ�ջ��
void push(int val) ��һ������ val ѹ��ջ����
int pop() ɾ�������ض�ջ�г���Ƶ����ߵ�Ԫ�ء�
�������Ƶ����ߵ�Ԫ�ز�ֻһ�������Ƴ���������ӽ�ջ����Ԫ�ء�
*/

class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        freq[val]++;
        group[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }

    int pop() {
        int val = group[maxFreq].top();
        freq[val]--;
        group[maxFreq].pop();
        if (group[maxFreq].empty()) {
            maxFreq--;
        }
        return val;
    }

private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq;
};
