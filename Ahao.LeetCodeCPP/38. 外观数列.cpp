using namespace std;
#include<string>


class Solution {
	/*
	38. 外观数列
	给定一个正整数 n ，输出外观数列的第 n 项。
	「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
	*/
public:
	string countAndSay(int n) {
		if (n == 1) return "1";
		string s = countAndSay(n - 1), ans;
		for (int i = 0, j = 0; i < s.length(); i++) {
			while (j < s.length() && s[i] == s[j]) j++;
			ans += to_string(j - i) + s[i];
			i = j - 1;
		}
		return ans;
	}
};

