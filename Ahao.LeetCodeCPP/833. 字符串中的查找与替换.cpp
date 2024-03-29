#include<vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;


/*
833. 字符串中的查找与替换

你会得到一个字符串 s (索引从 0 开始)，你必须对它执行 k 个替换操作。替换操作以三个长度均为 k 的并行数组给出：indices, sources,  targets。

要完成第 i 个替换操作:

检查 子字符串  sources[i] 是否出现在 原字符串 s 的索引 indices[i] 处。
如果没有出现， 什么也不做 。
如果出现，则用 targets[i] 替换 该子字符串。
例如，如果 s = "abcd" ， indices[i] = 0 , sources[i] = "ab"， targets[i] = "eee" ，那么替换的结果将是 "eeecd" 。

所有替换操作必须 同时 发生，这意味着替换操作不应该影响彼此的索引。测试用例保证元素间不会重叠 。

例如，一个 s = "abc" ，  indices = [0,1] ， sources = ["ab"，"bc"] 的测试用例将不会生成，因为 "ab" 和 "bc" 替换重叠。
在对 s 执行所有替换操作后返回 结果字符串 。

子字符串 是字符串中连续的字符序列。



示例 1：



输入：s = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
输出："eeebffff"
解释：
"a" 从 s 中的索引 0 开始，所以它被替换为 "eee"。
"cd" 从 s 中的索引 2 开始，所以它被替换为 "ffff"。
示例 2：

输入：s = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
输出："eeecd"
解释：
"ab" 从 s 中的索引 0 开始，所以它被替换为 "eee"。
"ec" 没有从原始的 S 中的索引 2 开始，所以它没有被替换。


提示：

1 <= s.length <= 1000
k == indices.length == sources.length == targets.length
1 <= k <= 100
0 <= indexes[i] < s.length
1 <= sources[i].length, targets[i].length <= 50
s 仅由小写英文字母组成
sources[i] 和 targets[i] 仅由小写英文字母组成
*/
class Solution {
public:
	string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
		int n = indices.size();
		vector<int> id(n);
		for (int i = 0; i < n; i++)
			id[i] = i;
		sort(id.begin(), id.end(), [&](int a, int b) {
			return indices[a] < indices[b];
			});

		for (int i = n - 1; i >= 0; i--)
		{
			int k = id[i];
			int j = indices[k], left = sources[k].size();
			if (s.substr(j, left) == sources[k])
				s = s.substr(0, j) + targets[k] + s.substr(j + left);
		}
		return s;
	}
};



class Solution {
public:
	string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
		int n = s.size(), m = indices.size();

		unordered_map<int, vector<int>> ops;
		for (int i = 0; i < m; ++i) {
			ops[indices[i]].push_back(i);
		}

		string ans;
		for (int i = 0; i < n;) {
			bool succeed = false;
			if (ops.count(i)) {
				for (int pt : ops[i]) {
					if (s.substr(i, sources[pt].size()) == sources[pt]) {
						succeed = true;
						ans += targets[pt];
						i += sources[pt].size();
						break;
					}
				}
			}
			if (!succeed) {
				ans += s[i];
				++i;
			}
		}
		return ans;
	}
};


class Solution {
public:
	string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
		int n = s.size(), m = indices.size();

		vector<int> ops(m);
		iota(ops.begin(), ops.end(), 0);
		sort(ops.begin(), ops.end(), [&](int i, int j) { return indices[i] < indices[j]; });

		string ans;
		int pt = 0;
		for (int i = 0; i < n;) {
			while (pt < m && indices[ops[pt]] < i) {
				++pt;
			}
			bool succeed = false;
			while (pt < m && indices[ops[pt]] == i) {
				if (s.substr(i, sources[ops[pt]].size()) == sources[ops[pt]]) {
					succeed = true;
					break;
				}
				++pt;
			}
			if (succeed) {
				ans += targets[ops[pt]];
				i += sources[ops[pt]].size();
			}
			else {
				ans += s[i];
				++i;
			}
		}
		return ans;
	}
};
