/*
有某个项目的n个选手进行循环比赛，其中n = 2 ^ m，要求每名选手要与其他 n - 1名选手都赛一次。
每名选手每天比赛一次，循环赛共进行 n - 1 天，要求每天没有选手轮空。

输入格式： m,m <= 5
输出格式：为n行n列的整形矩阵，即比赛表格

输入样例 2
输出样例
1	2	3	4
2	1	4	3
3	4	1	2
4	3	2	1

*/


//循环比赛
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>

using namespace std;

int i, j, h, person, n;
int a[32 + 1][32 + 1];

int main() {
	cin >> n;
	person = 1;
	a[1][1] = 1;
	h = 1;
	for (i = 1; i <= n; i++) {
		person = person * 2;
	}
	do {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= h; j++) {
				a[i][j + h] = a[i][j] + h;	//构造右上角方阵
				a[i + h][j] = a[i][j + h];	//构造左下角方阵
				a[i + h][j + h] = a[i][j];	//构造右下角方阵
			}
		}
		h = h * 2;
	} while (!(h == person));

	for (i = 1; i <= person; i++) {
		for (j = 1; j <= person; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << "\n";
	}
	return 0;
}