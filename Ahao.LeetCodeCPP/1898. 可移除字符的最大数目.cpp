#include<vector>
#include<string>
#include<unordered_set>

using namespace std;



/*
1898. 可移除字符的最大数目
给你两个字符串 s 和 p ，其中 p 是 s 的一个 子序列 。同时，给你一个元素 互不相同 且下标 从 0 开始 计数的整数数组 removable ，该数组是 s 中下标的一个子集（s 的下标也 从 0 开始 计数）。

请你找出一个整数 k（0 <= k <= removable.length），选出 removable 中的 前 k 个下标，然后从 s 中移除这些下标对应的 k 个字符。整数 k 需满足：在执行完上述步骤后， p 仍然是 s 的一个 子序列 。更正式的解释是，对于每个 0 <= i < k ，先标记出位于 s[removable[i]] 的字符，接着移除所有标记过的字符，然后检查 p 是否仍然是 s 的一个子序列。

返回你可以找出的 最大 k ，满足在移除字符后 p 仍然是 s 的一个子序列。

字符串的一个 子序列 是一个由原字符串生成的新字符串，生成过程中可能会移除原字符串中的一些字符（也可能不移除）但不改变剩余字符之间的相对顺序。
*/
class Solution {
public:
	int maximumRemovals(string s, string p, vector<int>& removable) {
		int left = 0, right = removable.size();
		while (left < right)
		{
			int mid = (left + right + 1) >> 1;
			unordered_set<int> hs;
			for (int i = 0; i < mid; i++) hs.insert(removable[i]);
			int i = 0, j = 0;
			while (i < s.size() && j < p.size())
			{
				if (hs.count(i))
				{
					i++;
					continue;
				}
				if (s[i] == p[j])j++;
				i++;
			}
			if (j == p.size()) left = mid;
			else right = mid - 1;
		}
		return right;
	}
};

