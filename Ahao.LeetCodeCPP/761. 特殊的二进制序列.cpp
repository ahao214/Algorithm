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
