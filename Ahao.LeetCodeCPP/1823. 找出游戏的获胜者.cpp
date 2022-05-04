using namespace std;

#include<queue>

class Solution {
public:
	//模拟+队列
	int findTheWinner(int n, int k) {
		queue<int> qu;
		for (int i = 1; i <= n; i++) {
			qu.emplace(i);
		}
		while (qu.size() > 1) {
			for (int i = 1; i < k; i++) {
				qu.emplace(qu.front());
				qu.pop();
			}
			qu.pop();
		}
		return qu.front();
	}
};


class Solution {
public:
	//数字+递归
	int findTheWinner(int n, int k) {
		if (n == 1) {
			return 1;
		}
		return (k + findTheWinner(n - 1, k) - 1) % n + 1;
	}
};


class Solution {
public:
	//数字+迭代
	int findTheWinner(int n, int k) {
		int winner = 1;
		for (int i = 2; i <= n; i++) {
			winner = (k + winner - 1) % i + 1;
		}
		return winner;
	}
};
