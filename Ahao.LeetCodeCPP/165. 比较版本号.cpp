#include<vector>
#include <string>

using namespace std;


/*
165. 比较版本号

给你两个版本号 version1 和 version2 ，请你比较它们。

版本号由一个或多个修订号组成，各修订号由一个 '.' 连接。每个修订号由 多位数字 组成，可能包含 前导零 。每个版本号至少包含一个字符。修订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0 ，下一个修订号下标为 1 ，以此类推。例如，2.5.33 和 0.1 都是有效的版本号。

比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较 忽略任何前导零后的整数值 。也就是说，修订号 1 和修订号 001 相等 。如果版本号没有指定某个下标处的修订号，则该修订号视为 0 。例如，版本 1.0 小于版本 1.1 ，因为它们下标为 0 的修订号相同，而下标为 1 的修订号分别为 0 和 1 ，0 < 1 。

返回规则如下：

如果 version1 > version2 返回 1，
如果 version1 < version2 返回 -1，
除此之外返回 0。
*/
class Solution {
public:
	vector<int> get_num(string version)
	{
		vector<int> res;
		for (int i = 0; i < version.size(); i++)
		{
			int j = i, s = 0;
			while (j < version.size() && version[j] != '.')
			{
				s = s * 10 + version[j] - '0';
				j++;
			}
			i = j;
			res.push_back(s);
		}
		while (res.size() && res.back() == 0) res.pop_back();
		return res;
	}

	int compareVersion(string version1, string version2) {
		auto n1 = get_num(version1);
		auto n2 = get_num(version2);
		if (n1 < n2) return -1;
		if (n1 == n2) return 0;
		return 1;
	}
};




class Solution {
public:
	int compareVersion(string version1, string version2) {
		for (int i = 0, j = 0; i < version1.size() || j < version2.size();)
		{
			int a = i, b = j;
			while (a < version1.size() && version1[a] != '.') a++;
			while (b < version2.size() && version2[b] != '.') b++;
			int x = a == i ? 0 : stoi(version1.substr(i, a - i));
			int y = b == j ? 0 : stoi(version2.substr(j, b - j));
			if (x > y) return 1;
			if (x < y) return -1;
			i = a + 1, j = b + 1;
		}
		return 0;
	}
};




class Solution {
public:
	int compareVersion(string version1, string version2) {
		int i = 0, n = version1.length();
		int j = 0, m = version2.length();

		while (i < n || j < m)
		{
			int a = 0, b = 0;
			while (i < n && version1[i] != '.')
				a = a * 10 + (version1[i++] - '0');
			i++;
			while (j < m&& version2[j] != '.')
				b = b * 10 + (version2[j++] - '0');
			j++;
			if (a != b)
				return a > b ? 1 : -1;
		}
		return 0;
	}
};