/*
找到最小自然数N，是N！在十进制下包含Q个零

输入格式：
一个数Q(0<=Q<=10^8)

输出格式：
如果无解，输出"No solution"，否则输出N

*/



/*
魔法石的诱惑——分治算法
*/
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



/*
魔法石的诱惑——数学方法
*/
int ZeroTrail(int n)	//计算N！的0的个数
{
	int count = 0;
	while (n)
	{
		count += n / 5;
		n /= 5;
	}
	return count;
}

int main() {
	int q;
	scanf("%d", &q);
	if (!q) {
		printf("1\n");
		return 0;
	}
	int i = 4 * q / 5 * 5;
	while (ZeroTrail(i) < q) {
		i += 5;
	}
	if (q == ZeroTrail(i))
	{
		printf("%d\n", i);
	}
	else
	{
		printf("No solution\n");
	}
	return 0;
}
