#include<vector>

using namespace std;

/*
855. 考场就座

在考场里，一排有 N 个座位，分别编号为 0, 1, 2, ..., N-1 。

当学生进入考场后，他必须坐在能够使他与离他最近的人之间的距离达到最大化的座位上。如果有多个这样的座位，他会坐在编号最小的座位上。(另外，如果考场里没有人，那么学生就坐在 0 号座位上。)

返回 ExamRoom(int N) 类，它有两个公开的函数：其中，函数 ExamRoom.seat() 会返回一个 int （整型数据），代表学生坐的位置；函数 ExamRoom.leave(int p) 代表坐在座位 p 上的学生现在离开了考场。每次调用 ExamRoom.leave(p) 时都保证有学生坐在座位 p 上。
*/

struct Comp {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        int d1 = p1.second - p1.first, d2 = p2.second - p2.first;
        return d1 / 2 < d2 / 2 || (d1 / 2 == d2 / 2 && p1.first > p2.first);
    }
};

class ExamRoom {
private:
    int n;
    set<int> seats;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

public:
    ExamRoom(int n) : n(n) {

    }

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        int left = *seats.begin(), right = n - 1 - *seats.rbegin();
        while (seats.size() >= 2) {
            auto p = pq.top();
            if (seats.count(p.first) > 0 && seats.count(p.second) > 0 &&
                *next(seats.find(p.first)) == p.second) { // 不属于延迟删除的区间
                int d = p.second - p.first;
                if (d / 2 < right || d / 2 <= left) { // 最左或最右的座位更优
                    break;
                }
                pq.pop();
                pq.push({ p.first, p.first + d / 2 });
                pq.push({ p.first + d / 2, p.second });
                seats.insert(p.first + d / 2);
                return p.first + d / 2;
            }
            pq.pop(); // leave 函数中延迟删除的区间在此时删除
        }
        if (right > left) { // 最右的位置更优
            pq.push({ *seats.rbegin(), n - 1 });
            seats.insert(n - 1);
            return n - 1;
        }
        else {
            pq.push({ 0, *seats.begin() });
            seats.insert(0);
            return 0;
        }
    }

    void leave(int p) {
        if (p != *seats.begin() && p != *seats.rbegin()) {
            auto it = seats.find(p);
            pq.push({ *prev(it), *next(it) });
        }
        seats.erase(p);
    }
};
