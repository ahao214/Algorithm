#include<vector>
#include<queue>

using namespace std;



/*
1845. ��λԤԼ����ϵͳ
�������һ������ n ����λԤԼ��ϵͳ����λ��Ŵ� 1 �� n ��

����ʵ�� SeatManager �ࣺ

SeatManager(int n) ��ʼ��һ�� SeatManager ����������� 1 �� n ��ŵ� n ����λ��������λ��ʼ���ǿ�ԤԼ�ġ�
int reserve() ���ؿ���ԤԼ��λ�� ��С��� ������λ��Ϊ����ԤԼ��
void unreserve(int seatNumber) ��������� seatNumber ��Ӧ����λ��ɿ���ԤԼ��
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



