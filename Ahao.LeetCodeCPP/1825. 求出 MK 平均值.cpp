#include<vector>
#include<queue>


using namespace std;

/*
1825. 求出 MK 平均值

给你两个整数 m 和 k ，以及数据流形式的若干整数。你需要实现一个数据结构，计算这个数据流的 MK 平均值 。

MK 平均值 按照如下步骤计算：

如果数据流中的整数少于 m 个，MK 平均值 为 -1 ，否则将数据流中最后 m 个元素拷贝到一个独立的容器中。
从这个容器中删除最小的 k 个数和最大的 k 个数。
计算剩余元素的平均值，并 向下取整到最近的整数 。
请你实现 MKAverage 类：

MKAverage(int m, int k) 用一个空的数据流和两个整数 m 和 k 初始化 MKAverage 对象。
void addElement(int num) 往数据流中插入一个新的元素 num 。
int calculateMKAverage() 对当前的数据流计算并返回 MK 平均数 ，结果需 向下取整到最近的整数 。
*/

class MKAverage {
private:
    int m, k;
    queue<int> q;
    multiset<int> s1, s2, s3;
    long long sum2;
public:
    MKAverage(int m, int k) : m(m), k(k) {
        sum2 = 0;
    }

    void addElement(int num) {
        q.push(num);
        if (q.size() <= m) {
            s2.insert(num);
            sum2 += num;
            if (q.size() == m) {
                while (s1.size() < k) {
                    s1.insert(*s2.begin());
                    sum2 -= *s2.begin();
                    s2.erase(s2.begin());
                }
                while (s3.size() < k) {
                    s3.insert(*s2.rbegin());
                    sum2 -= *s2.rbegin();
                    s2.erase(prev(s2.end()));
                }
            }
            return;
        }

        if (num < *s1.rbegin()) {
            s1.insert(num);
            s2.insert(*s1.rbegin());
            sum2 += *s1.rbegin();
            s1.erase(prev(s1.end()));
        }
        else if (num > *s3.begin()) {
            s3.insert(num);
            s2.insert(*s3.begin());
            sum2 += *s3.begin();
            s3.erase(s3.begin());
        }
        else {
            s2.insert(num);
            sum2 += num;
        }

        int x = q.front();
        q.pop();
        if (s1.count(x) > 0) {
            s1.erase(s1.find(x));
            s1.insert(*s2.begin());
            sum2 -= *s2.begin();
            s2.erase(s2.begin());
        }
        else if (s3.count(x) > 0) {
            s3.erase(s3.find(x));
            s3.insert(*s2.rbegin());
            sum2 -= *s2.rbegin();
            s2.erase(prev(s2.end()));
        }
        else {
            s2.erase(s2.find(x));
            sum2 -= x;
        }
    }

    int calculateMKAverage() {
        if (q.size() < m) {
            return -1;
        }
        return sum2 / (m - 2 * k);
    }
};
