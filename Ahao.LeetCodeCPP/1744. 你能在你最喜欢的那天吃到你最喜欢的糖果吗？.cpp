#include<vector>

using namespace std;



/*
1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
给你一个下标从 0 开始的正整数数组 candiesCount ，其中 candiesCount[i] 表示你拥有的第 i 类糖果的数目。同时给你一个二维数组 queries ，其中 queries[i] = [favoriteTypei, favoriteDayi, dailyCapi] 。

你按照如下规则进行一场游戏：

你从第 0 天开始吃糖果。
你在吃完 所有 第 i - 1 类糖果之前，不能 吃任何一颗第 i 类糖果。
在吃完所有糖果之前，你必须每天 至少 吃 一颗 糖果。
请你构建一个布尔型数组 answer ，用以给出 queries 中每一项的对应答案。此数组满足：

answer.length == queries.length 。answer[i] 是 queries[i] 的答案。
answer[i] 为 true 的条件是：在每天吃 不超过 dailyCapi 颗糖果的前提下，你可以在第 favoriteDayi 天吃到第 favoriteTypei 类糖果；否则 answer[i] 为 false 。
注意，只要满足上面 3 条规则中的第二条规则，你就可以在同一天吃不同类型的糖果。

请你返回得到的数组 answer 。
*/
class Solution {
public:
	typedef long long LL;
	bool check(LL a, LL b, LL c, LL d)
	{
		if (b < c || d < a)
			return false;
		return true;
	}

	vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
		int n = candiesCount.size();
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + candiesCount[i - 1];

		vector<bool> res;
		for (auto& q : queries)
		{
			//t表示糖果的种类 d表示第几天 c表示每天最多吃的糖果的数量
			int t = q[0], d = q[1], c = q[2];
			res.push_back(check(d + 1, (LL)(d + 1) * c, s[t] + 1, s[t + 1]));
		}

		return res;
	}
};