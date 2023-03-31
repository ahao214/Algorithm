#include<vector>
#include <string>

using namespace std;


/*
831. 隐藏个人信息

给你一条个人信息字符串 s ，可能表示一个 邮箱地址 ，也可能表示一串 电话号码 。返回按如下规则 隐藏 个人信息后的结果：

电子邮件地址：

一个电子邮件地址由以下部分组成：

一个 名字 ，由大小写英文字母组成，后面跟着
一个 '@' 字符，后面跟着
一个 域名 ，由大小写英文字母和一个位于中间的 '.' 字符组成。'.' 不会是域名的第一个或者最后一个字符。
要想隐藏电子邮件地址中的个人信息：

名字 和 域名 部分的大写英文字母应当转换成小写英文字母。
名字 中间的字母（即，除第一个和最后一个字母外）必须用 5 个 "*****" 替换。
电话号码：

一个电话号码应当按下述格式组成：

电话号码可以由 10-13 位数字组成
后 10 位构成 本地号码
前面剩下的 0-3 位，构成 国家代码
利用 {'+', '-', '(', ')', ' '} 这些 分隔字符 按某种形式对上述数字进行分隔
要想隐藏电话号码中的个人信息：

移除所有 分隔字符
隐藏个人信息后的电话号码应该遵从这种格式：
"***-***-XXXX" 如果国家代码为 0 位数字
"+*-***-***-XXXX" 如果国家代码为 1 位数字
"+**-***-***-XXXX" 如果国家代码为 2 位数字
"+***-***-***-XXXX" 如果国家代码为 3 位数字
"XXXX" 是最后 4 位 本地号码
*/


class Solution {
public:
	string workEmail(string t)
	{
		string s;
		for (auto c : t)
			s += tolower(c);
		int a = s.find('@'), b = s.find('.');
		string name1 = s.substr(0, a);
		string name2 = s.substr(a + 1, b - a - 1);
		string name3 = s.substr(b + 1);
		return name1[0] + string(5, '*') + name1.back() + '@' + name2 + '.' + name3;
	}

	string workPhone(string t)
	{
		string s;
		for (auto c : t)
		{
			if (isdigit(c))
				s += c;
		}
		if (s.size() == 10)
			return "***-***-" + s.substr(6);
		return "+" + string(s.size() - 10, '*') + "-***-***-" + s.substr(s.size() - 4);
	}

	string maskPII(string s) {
		if (s.find('@') != -1)
			return workEmail(s);
		else
			return workPhone(s);
	}
};


class Solution {
public:
	vector<string> country = { "", "+*-", "+**-", "+***-" };

	string maskPII(string s) {
		string res;
		int at = s.find("@");
		if (at != string::npos) {
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			return s.substr(0, 1) + "*****" + s.substr(at - 1);
		}
		s = regex_replace(s, regex("[^0-9]"), "");
		return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
	}
};

