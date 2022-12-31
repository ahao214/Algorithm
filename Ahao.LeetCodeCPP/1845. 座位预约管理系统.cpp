#include<vector>
#include<queue>

using namespace std;



/*
1845. 座位预约管理系统
请你设计一个管理 n 个座位预约的系统，座位编号从 1 到 n 。

请你实现 SeatManager 类：

SeatManager(int n) 初始化一个 SeatManager 对象，它管理从 1 到 n 编号的 n 个座位。所有座位初始都是可预约的。
int reserve() 返回可以预约座位的 最小编号 ，此座位变为不可预约。
void unreserve(int seatNumber) 将给定编号 seatNumber 对应的座位变成可以预约。
*/
class Solution {
public:
	priority_queue<int, vector<int>, greater<int>> heap;
	void SeatManager(int n) {
		for (int i = 1; i <= n; i++)
			heap.push(i);
	}

	int reserve() {
		int t = heap.top();
		heap.pop();
		return t;
	}

	void unreserve(int seatNumber) {
		heap.push(seatNumber);
	}

};



