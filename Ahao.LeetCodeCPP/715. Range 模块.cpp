#include<vector>
#include<string>

using namespace std;

/*
715. Range ģ��

Rangeģ���Ǹ������ַ�Χ��ģ�顣���һ�����ݽṹ�����ٱ�ʾΪ �뿪���� �ķ�Χ����ѯ���ǡ�

�뿪���� [left, right) ��ʾ���� left <= x < right ��ʵ�� x ��

ʵ�� RangeModule ��:

RangeModule() ��ʼ�����ݽṹ�Ķ���
void addRange(int left, int right) ��� �뿪���� [left, right)�����ٸ������е�ÿ��ʵ��������뵱ǰ���ٵ����ֲ����ص�������ʱ��Ӧ����������� [left, right) ����δ���ٵ��κ����ֵ��������С�
boolean queryRange(int left, int right) ֻ���ڵ�ǰ���ڸ������� [left, right) �е�ÿһ��ʵ��ʱ���ŷ��� true �����򷵻� false ��
void removeRange(int left, int right) ֹͣ���� �뿪���� [left, right) �е�ǰ���ڸ��ٵ�ÿ��ʵ����
*/

class RangeModule {
public:
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                return;
            }
            if (start->second >= left) {
                left = start->first;
                intervals.erase(start);
            }
        }
        while (it != intervals.end() && it->first <= right) {
            right = max(right, it->second);
            it = intervals.erase(it);
        }
        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) {
            return false;
        }
        it = prev(it);
        return right <= it->second;
    }

    void removeRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                int ri = start->second;
                if (start->first == left) {
                    intervals.erase(start);
                }
                else {
                    start->second = left;
                }
                if (right != ri) {
                    intervals[right] = ri;
                }
                return;
            }
            else if (start->second > left) {
                if (start->first == left) {
                    intervals.erase(start);
                }
                else {
                    start->second = left;
                }
            }
        }
        while (it != intervals.end() && it->first < right) {
            if (it->second <= right) {
                it = intervals.erase(it);
            }
            else {
                intervals[right] = it->second;
                intervals.erase(it);
                break;
            }
        }
    }

private:
    map<int, int> intervals;
};

