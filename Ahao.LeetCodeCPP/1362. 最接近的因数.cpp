#include<vector>

using namespace std;


/*
1362. 最接近的因数
给你一个整数 num，请你找出同时满足下面全部要求的两个整数：

两数乘积等于  num + 1 或 num + 2
以绝对差进行度量，两数大小最接近
你可以按任意顺序返回这两个整数。
*/
class Solution {
public:
	vector<int> closestDivisors(int num) {
		for (int i = sqrt(num + 2); i; i--)
		{
			if ((num + 1) % i == 0) return { i,(num + 1) / i };
			if ((num + 2) % i == 0) return { i,(num + 2) / i };
		}
		return {};
	}
};