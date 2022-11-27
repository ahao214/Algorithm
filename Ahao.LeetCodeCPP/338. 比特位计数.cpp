#include<vector>

using namespace std;


/*
338. 比特位计数
给你一个整数 n ，对于 0 <= i <= n 中的每个 i
计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。
*/
class Solution {
public:
	vector<int> countBits(int n) {
		//如果n是奇数，p[n]=p[n-1]+1
		//如果n是偶数，p[n]=p[n/2]
		vector<int> res(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 1)
			{
				res[i] = res[i - 1] + 1;
			}
			else
			{
				res[i] = res[i / 2];
			}
		}
		return res;
	}
};
