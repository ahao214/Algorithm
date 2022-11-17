#include<vector>
#include <algorithm>

using namespace std;


/*
1560. 圆形赛道上经过次数最多的扇区
给你一个整数 n 和一个整数数组 rounds 。有一条圆形赛道由 n 个扇区组成，扇区编号从 1 到 n 。现将在这条赛道上举办一场马拉松比赛，该马拉松全程由 m 个阶段组成。其中，第 i 个阶段将会从扇区 rounds[i - 1] 开始，到扇区 rounds[i] 结束。举例来说，第 1 阶段从 rounds[0] 开始，到 rounds[1] 结束。

请你以数组形式返回经过次数最多的那几个扇区，按扇区编号 升序 排列。
*/
class Solution {
public:
	vector<int> mostVisited(int n, vector<int>& rounds) {
		vector<int> s(n + 1);
		for (int i = 0; i + 1 < rounds.size(); i++)
		{
			int a = rounds[i], b = rounds[i + 1];
			while (a != b)
			{
				s[a]++;
				a++;
				if (a > n) a -= n;
			}
		}
		s[rounds.back()]++;
		int c = 0;
		for (auto x : s) c = max(x, c);
		vector<int> res;
		for (int i = 1; i <= n; i++)
			if (s[i] == c)
				res.push_back(i);
		return res;
	}

	vector<int> mostVisited(int n, vector<int>& rounds) {
		vector<int> res;
		//a表示第一个 b表示最后一个
		int a = rounds[0], b = rounds.back();
		if (b == a - 1 || (a == 1 && b == n))
		{
			for (int i = 1; i <= n; i++)
				res.push_back(i);
		}
		else {
			while (a != b)
			{
				res.push_back(a);
				if (++a > n) a -= n;
			}
			res.push_back(b);
			sort(res.begin(), res.end());
		}
		return res;
	}
};