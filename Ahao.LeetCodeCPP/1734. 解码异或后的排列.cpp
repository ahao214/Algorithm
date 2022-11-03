#include<vector>

using namespace std;



/*
1734. 解码异或后的排列
给你一个整数数组 perm ，它是前 n 个正整数的排列，且 n 是个 奇数 。

它被加密成另一个长度为 n - 1 的整数数组 encoded ，满足 encoded[i] = perm[i] XOR perm[i + 1] 。比方说，如果 perm = [1,3,2] ，那么 encoded = [2,1] 。

给你 encoded 数组，请你返回原始数组 perm 。题目保证答案存在且唯一。
*/
class Solution {
public:
	vector<int> decode(vector<int>& encoded) {
		int sum = 0;
		int n = encoded.size() + 1;
		for (int i = 1; i <= n; i++)
			sum ^= i;
		for (int i = encoded.size() - 1; i >= 0; i -= 2)
			sum ^= encoded[i];
		vector<int> a(1, sum);
		for (int i = 0; i < encoded.size(); i++)
			a.push_back(a.back() ^ encoded[i]);
		return a;
	}
};
