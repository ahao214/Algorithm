#include<vector>

using namespace std;

/*
2347. 最好的扑克手牌

给你一个整数数组 ranks 和一个字符数组 suit 。你有 5 张扑克牌，第 i 张牌大小为 ranks[i] ，花色为 suits[i] 。

下述是从好到坏你可能持有的 手牌类型 ：

"Flush"：同花，五张相同花色的扑克牌。
"Three of a Kind"：三条，有 3 张大小相同的扑克牌。
"Pair"：对子，两张大小一样的扑克牌。
"High Card"：高牌，五张大小互不相同的扑克牌。
请你返回一个字符串，表示给定的 5 张牌中，你能组成的 最好手牌类型 。

注意：返回的字符串 大小写 需与题目描述相同。
*/


class Solution {
public:
	string bestHand(vector<int>& ranks, vector<char>& suits) {
		unordered_set<char> suitsSet;
		for (char suit : suits) {
			suitsSet.emplace(suit);
		}
		if (suitsSet.size() == 1) {
			return "Flush";
		}
		unordered_map<int, int> h;
		for (int rank : ranks) {
			h[rank]++;
		}
		if (h.size() == 5) {
			return "High Card";
		}
		for (auto [_, val] : h) {
			if (val > 2) {
				return "Three of a Kind";
			}
		}
		return "Pair";
	}
};