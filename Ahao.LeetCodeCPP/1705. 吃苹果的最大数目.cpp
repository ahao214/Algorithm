#include<vector>
#include <queue>

using namespace std;



/*
1705. 吃苹果的最大数目
有一棵特殊的苹果树，一连 n 天，每天都可以长出若干个苹果。在第 i 天，树上会长出 apples[i] 个苹果，这些苹果将会在 days[i] 天后（也就是说，第 i + days[i] 天时）腐烂，变得无法食用。也可能有那么几天，树上不会长出新的苹果，此时用 apples[i] == 0 且 days[i] == 0 表示。

你打算每天 最多 吃一个苹果来保证营养均衡。注意，你可以在这 n 天之后继续吃苹果。

给你两个长度为 n 的整数数组 days 和 apples ，返回你可以吃掉的苹果的最大数目。
*/
class Solution {
public:
	int eatenApples(vector<int>& apples, vector<int>& days) {
		typedef pair<int, int> PII;
		//小根堆
		priority_queue<PII, vector<PII>, greater<PII>> heap;
		int res = 0;
		int n = apples.size();
		for (int i = 0; i <= 40000; i++)
		{
			if (i < n && apples[i] > 0)
			{
				heap.push({ i + days[i] - 1,apples[i] });
			}
			while (heap.size() && heap.top().first < i) heap.pop();
			if (heap.empty()) continue;
			auto t = heap.top();
			heap.pop();
			res++;
			if (--t.second)
			{
				heap.push(t);
			}
		}
		return res;
	}
};