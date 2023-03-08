#include<vector>
#include<string>
#include<algorithm>
#include <numeric>

using namespace std;



/*
761. 特殊的二进制序列
*/
class Solution {
public:
	string makeLargestSpecial(string s) {
		if (s.size() <= 2) {
			return s;
		}
		int cnt = 0, left = 0;
		vector<string> subs;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '1') {
				++cnt;
			}
			else {
				--cnt;
				if (cnt == 0) {
					subs.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
					left = i + 1;
				}
			}
		}

		sort(subs.begin(), subs.end(), greater<string>{});
		string ans = accumulate(subs.begin(), subs.end(), ""s);
		return ans;
	}
};


class Solution {
public:
	string makeLargestSpecial(string s) {
		vector<string> v;
		for (int i = 0, cur = 0, last = 0; i < s.size(); ++i) {
			(s[i] == '1') ? cur++ : cur--;
			if (cur == 0) {
				v.push_back("1");
				v.back() += makeLargestSpecial(s.substr(last + 1, i - last - 1)) + '0';
				last = i + 1;
			}
		}
		sort(v.begin(), v.end(), greater<string>());

		string res;
		for (auto& r : v) {
			res += r;
		}
		return res;
	}
};





/*
761. 特殊的二进制序列

特殊的二进制序列是具有以下两个性质的二进制序列：

0 的数量与 1 的数量相等。
二进制序列的每一个前缀码中 1 的数量要大于等于 0 的数量。
给定一个特殊的二进制序列 S，以字符串形式表示。定义一个操作 为首先选择 S 的两个连续且非空的特殊的子串，然后将它们交换。（两个子串为连续的当且仅当第一个子串的最后一个字符恰好为第二个子串的第一个字符的前一个字符。)

在任意次数的操作之后，交换后的字符串按照字典序排列的最大的结果是什么？
*/
class Solution {
public:
	string makeLargestSpecial(string s) {
		vector<string> v;
		for (int i = 0, cur = 0, last = 0; i < s.size(); ++i) {
			(s[i] == '1') ? cur++ : cur--;
			if (cur == 0) {
				v.push_back("1");
				v.back() += makeLargestSpecial(s.substr(last + 1, i - last - 1)) + '0';
				last = i + 1;
			}
		}
		sort(v.begin(), v.end(), greater<string>());

		string res;
		for (auto& r : v) {
			res += r;
		}
		return res;
	}
};

