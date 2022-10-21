#include<stack>


using namespace std;

/*
901. ��Ʊ�۸���
��дһ�� StockSpanner �࣬���ռ�ĳЩ��Ʊ��ÿ�ձ��ۣ������ظù�Ʊ���ռ۸�Ŀ�ȡ�

�����Ʊ�۸�Ŀ�ȱ�����Ϊ��Ʊ�۸�С�ڻ���ڽ���۸����������������ӽ��쿪ʼ���������������죩��

���磬���δ��7���Ʊ�ļ۸��� [100, 80, 60, 70, 60, 75, 85]����ô��Ʊ��Ƚ��� [1, 1, 1, 2, 1, 4, 6]��
*/

class StockSpanner {
public:
    StockSpanner() {
        this->stk.emplace(-1, INT_MAX);
        this->idx = -1;
    }

    int next(int price) {
        idx++;
        while (price >= stk.top().second) {
            stk.pop();
        }
        int ret = idx - stk.top().first;
        stk.emplace(idx, price);
        return ret;
    }

private:
    stack<pair<int, int>> stk;
    int idx;
};
