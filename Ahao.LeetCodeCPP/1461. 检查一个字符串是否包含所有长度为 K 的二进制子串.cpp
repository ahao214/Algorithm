#include<vector>
#include <unordered_set>

using namespace std;


/*
1461. 检查一个字符串是否包含所有长度为 K 的二进制子串
给你一个二进制字符串 s 和一个整数 k 。如果所有长度为 k 的二进制字符串都是 s 的子串，请返回 true ，否则请返回 false 。
*/
class Solution {
public:
	/*
	将s中所有长度为k的子串，存储到一个哈希表里面
	计算哈希表里面的值的总个数是否等于2^k
	为了节省时间和空间，哈希表里面保存的长度为k的子串所对应的十进制数字
	*/
	bool hasAllCodes(string s, int k) {
		unordered_set<int> S;
		for (int i = 0, w = 0; i < s.size(); i++)
		{
			w = w * 2 + s[i] - '0';
			if (i >= k) w -= s[i - k] - '0' << k;
			if (i >= k - 1) S.insert(w);
		}
		return S.size() == (1 << k);
	}
};
