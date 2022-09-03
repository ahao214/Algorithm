/*
输入格式：输入文件的第一行是N，表示有N个元素，第二行是N个数，第三行是M表示要查找的数字
输出格式：一个数，即如找打该数字，则输出位置，否则输出-1
输入样例：
3
2	4	6
4
输出样例：
2
因为数字4在N个数中的位置是第二
*/

/*
递归二分算法
将已经排好序的数列依次存入数组a[]，设置要查找数值为X，用指针bot指向数列最左端位置(最小值)，指针top指向数列最右端位置(最大值)，取bot和top的中间值mid指向数列中间
当top > bot 时，比较查找X与a[mid]，有3种可能
1、若 X = a[mid] 则表示找到，退出比较查找
2、若 X < a[mid] 则选择前半段继续比较查找，bot不变，top变成 mid - 1
3、若 X > a[mid] 则选择后半段继续比较查找，bot变成 mid + 1，top不变
结束的过程有两种：一种是找到了X = a[mid];另一种是没找到，即 top < bot
*/


/*
折半查找法——递归二分算法
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define Max 10001
using namespace std;
int a[Max], key;

int search(int bot, int top) {
	int mid;
	if (top >= bot) {
		mid = (top + bot) / 2;
		if (key == a[mid]) {
			cout << mid << endl;
			return 0;
		}
		else if (key < a[mid]) {
			search(bot, mid - 1);
		}
		else {
			search(mid + 1, top);
		}
	}
	else
	{
		printf("-1\n");
		return 0;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> key;
	search(1, n);
	return 0;
}