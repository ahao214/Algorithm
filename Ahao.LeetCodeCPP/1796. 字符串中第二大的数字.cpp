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


class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (auto c : s) {
            if (isdigit(c)) {
                int num = c - '0';
                if (num > first) {
                    second = first;
                    first = num;
                }
                else if (num < first && num > second) {
                    second = num;
                }
            }
        }
        return second;
    }
};
