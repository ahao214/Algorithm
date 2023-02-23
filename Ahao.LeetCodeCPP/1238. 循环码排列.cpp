#include<vector>

using namespace std;


/*
1238. 循环码排列

给你两个整数 n 和 start。你的任务是返回任意 (0,1,2,,...,2^n-1) 的排列 p，并且满足：

p[0] = start
p[i] 和 p[i+1] 的二进制表示形式只有一位不同
p[0] 和 p[2^n -1] 的二进制表示形式也只有一位不同
*/

//归纳法
class Solution {
public:
	vector<int> circularPermutation(int n, int start) {
		vector<int> ret;
		ret.reserve(1 << n);
		ret.push_back(start);
		for (int i = 1; i <= n; i++) {
			int m = ret.size();
			for (int j = m - 1; j >= 0; j--) {
				ret.push_back(((ret[j] ^ start) | (1 << (i - 1))) ^ start);
			}
		}
		return ret;
	}
};


//公式法
class Solution {
public:
	vector<int> circularPermutation(int n, int start) {
		vector<int> ret(1 << n);
		for (int i = 0; i < ret.size(); i++) {
			ret[i] = (i >> 1) ^ i ^ start;
		}
		return ret;
	}
};
