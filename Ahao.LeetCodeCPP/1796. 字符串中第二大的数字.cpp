#include<string>
#include<set>

using namespace std;

/*
1796. 字符串中第二大的数字
给你一个混合字符串 s ，请你返回 s 中 第二大 的数字，如果不存在第二大的数字，请你返回 -1 。

混合字符串 由小写英文字母和数字组成。
*/
class Solution {
public:
	int secondHighest(string s) {
		set<int> nset;
		for (auto c : s)
		{
			if (isdigit(c))
				nset.insert(c - '0');
		}
		if (nset.size() <= 1) return -1;
		auto it = nset.rbegin();
		it++;
		return *it;
	}
};
