#include<string>
#include<stack>
#include <vector>

using namespace std;




class Solution {
public:
	/*
	Times:O(n)
	Space:O(n)
	*/
	string simplifyPath(string path) {
		stack<string> stk;
		stringstream ss(path);
		string item;
		while (getline(ss, item, '/'))
		{
			if (item == "..")
			{
				if (!stk.empty())
					stk.pop();
			}
			else if (item != "." && item != "")
			{
				stk.push(item);
			}
		}
		string ans;
		while (!stk.empty())
		{
			ans = "/" + stk.top() + ans;
		}
		return ans.empty() ? "/" : ans;
	}
};




/*
71. 简化路径
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。

请注意，返回的 规范路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。
*/
class Solution {
public:
	string simplifyPath(string path) {
		path + = '/';
		string res, s;
		for (auto c : path)
		{
			if (res.empty()) res += c;
			else if (c != '/') s += c;
			else
			{
				if (s == "..")
				{
					if (res.size() > 1)
					{
						res.pop_back();
						while (res.back() != '/') res.pop_back();
					}
				}
				else if (s != "" && s != ".")
				{
					res += s + '/';
				}
				s = "";
			}
		}
		if (res.size() > 1) res.pop_back();
		return res;
	}
};




/*
71. 简化路径
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。

请注意，返回的 规范路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。
*/
class Solution {
public:
	string simplifyPath(string path) {
		stringstream ss(path);
		string res, tmp;
		vector<string> stk;
		while (getline(ss, tmp, '/'))
		{
			if (tmp.empty() || tmp == ".")
			{
				continue;
			}
			if (tmp == ".." && !stk.empty())
			{
				stk.pop_back();
			}
			else if (tmp != "..")
			{
				stk.push_back(tmp);
			}
		}

		for (auto s : stk)
		{
			res += "/" + s;
		}
		return res.empty() ? "/" : res;
	}
};