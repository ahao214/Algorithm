using namespace std;
#include<string>
#include<vector>
#include <unordered_set>


/*
929. 独特的电子邮件地址

每个 有效电子邮件地址 都由一个 本地名 和一个 域名 组成，以 '@' 符号分隔。除小写字母之外，电子邮件地址还可以含有一个或多个 '.' 或 '+' 。

例如，在 alice@leetcode.com中， alice 是 本地名 ，而 leetcode.com 是 域名 。
如果在电子邮件地址的 本地名 部分中的某些字符之间添加句点（'.'），则发往那里的邮件将会转发到本地名中没有点的同一地址。请注意，此规则 不适用于域名 。

例如，"alice.z@leetcode.com” 和 “alicez@leetcode.com” 会转发到同一电子邮件地址。
如果在 本地名 中添加加号（'+'），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件。同样，此规则 不适用于域名 。

例如 m.y+name@email.com 将转发到 my@email.com。
可以同时使用这两个规则。

给你一个字符串数组 emails，我们会向每个 emails[i] 发送一封电子邮件。
返回实际收到邮件的不同地址数目。
*/

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> emailSet;
		for (auto& email : emails) {
			string local;
			for (char c : email) {
				if (c == '+' || c == '@') {
					break;
				}
				if (c != '.') {
					local += c;
				}
			}
			emailSet.emplace(local + email.substr(email.find('@')));
		}
		return emailSet.size();
	}
};





class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> hash;
		for (auto email : emails)
		{
			int at = email.find('@');
			string name;
			for (char c : email.substr(0, at))
			{
				if (c == '+') break;
				else if (c != '.') name += c;
			}
			string domain = email.substr(at + 1);
			hash.insert(name + '@' + domain);
		}
		return hash.size();
	}
};



class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> S;
		for (auto& s : emails)
		{
			int k = s.find('@');
			auto a = s.substr(0, k), b = s.substr(k + 1);
			string c;
			for (auto x : a)
				if (x == '+') break;
				else if (x != '.') c += x;
			S.insert(c + '@' + b);
		}
		return S.size();
	}
};