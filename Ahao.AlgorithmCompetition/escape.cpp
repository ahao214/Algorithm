/*
两人需要从A地出发尽快到B地。
出发时A地有一辆可带一人的自动驾驶悬浮车。又知道两人步行速度相同。
问怎么样利用小车才能使两人尽快同时到达B地？

有三个int类型整数，分别表示A、B两地的距离，步行速度和车速

输入样例：
100 5 10
输出样例：
14.00
*/

//逃亡——分治算法
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;


int main() {
	float s, a, b, c, c0, c1, t1, t2, t3, t4;
	cin >> s >> a >> b;
	c0 = 0;
	c1 = s;
	do {
		c = (c0 + c1) / 2.0;
		t3 = c / b;					//甲乘车到C的时间
		t1 = t3 + (s - c) / s;	//甲用的总时间
		t4 = (c - t3 * a) / (a + b);	//小车从C回头与乙相遇的时间
		t2 = t3 + t4 + (s - (t3 + t4) * a) / b;		//乙用的时间
		if (t1 < t2) {
			c1 = c;
		}
		else {
			c0 = c;
		}
	} while (fabs(t1 - t2) > 1e-4);
	printf("%4.2f", t1);
	return 0;
}

