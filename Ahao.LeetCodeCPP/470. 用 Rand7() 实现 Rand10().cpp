#include<vector>
#include<algorithm>

using namespace std;


/*
470. 用 Rand7() 实现 Rand10()

给定方法 rand7 可生成 [1,7] 范围内的均匀随机整数，试写一个方法 rand10 生成 [1,10] 范围内的均匀随机整数。

你只能调用 rand7() 且不能调用其他方法。请不要使用系统的 Math.random() 方法。

每个测试用例将有一个内部参数 n，即你实现的函数 rand10() 在测试时将被调用的次数。请注意，这不是传递给 rand10() 的参数。
*/
class Solution {
public:
	int rand10() {
		int t = (rand7() - 1) * 7 + rand7();	//1~49

		if (t > 40) return rand10();
		return (t - 1) % 10 + 1;
	}
};
