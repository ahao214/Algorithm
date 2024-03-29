#include<vector>

using namespace std;


class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> answer;
		for (int i = 1; i < n - k; ++i) {
			answer.push_back(i);
		}
		for (int i = n - k, j = n; i <= j; ++i, --j) {
			answer.push_back(i);
			if (i != j) {
				answer.push_back(j);
			}
		}
		return answer;
	}
};





/*
667. 优美的排列 II

给你两个整数 n 和 k ，请你构造一个答案列表 answer ，该列表应当包含从 1 到 n 的 n 个不同正整数，并同时满足下述条件：

假设该列表是 answer = [a1, a2, a3, ... , an] ，那么列表 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数。
返回列表 answer 。如果存在多种答案，只需返回其中 任意一种 。
*/
class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> res(n);
		for (int i = 0; i < n - k - 1; i++)
			res[i] = i + 1;
		int u = n - k - 1;
		for (int i = n - k, j = n; u < n; i++, j--)
		{
			res[u++] = i;
			if (u < n)
				res[u++] = j;
		}
		return res;
	}
};
