/*
�ҵ���С��Ȼ��N����N����ʮ�����°���Q����

�����ʽ��
һ����Q(0<=Q<=10^8)

�����ʽ��
����޽⣬���"No solution"���������N

*/



//ħ��ʯ���ջ󡪡������㷨
#include<iostream>
#include<cstdint>
#include<cstdio>

using namespace std;

int solve(int n)
{
	int ans = 0;
	while (n > 0) {
		ans = ans + n / 5;
		n = n / 5;
	}
	return ans;
}

void run()
{
	int Q, i;
	scanf("%d", &Q);
	int start = 1;
	int end = 500000000;
	int ans = 500000001;
	int mid;
	int t;
	while (start <= end) {
		int mi = (end - start) / 2 + start;
		int t = solve(mid);
		if (t == Q && mid < ans) {
			ans = mid;
		}
		if (t > Q) {
			end = mid - 1;
		}
		else if (t < Q) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	if (ans != 500000001) {
		printf("%d\n", ans);
	}
	else {
		printf("No solution");
	}
}

int main() {
	run();
	return 0;
}