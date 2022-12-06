using namespace std;
#include<string>

/*
38. 外观数列
给定一个正整数 n ，输出外观数列的第 n 项。
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
*/
class Solution {
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


/*
38. 外观数列
给定一个正整数 n ，输出外观数列的第 n 项。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。

你可以将其视作是由递归公式定义的数字字符串序列：

countAndSay(1) = "1"
countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。
*/
class Solution {
public:
	string countAndSay(int n) {
		string s = "1";
		for (int i = 0; i < n - 1; i++)
		{
			string ns;
			//遍历连续的
			for (int j = 0; j < s.size(); j++)
			{
				int k = j;
				while (k < s.size() && s[k] == s[j]) k++;
				ns += to_string(k - j) + s[j];
				j = k - 1;
			}
			s = ns;
		}
		return s;
	}
};


