using namespace std;
#include<vector>
#include<string>

class Solution {
	/*
	60. 排列序列
	给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

	按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

	"123"
	"132"
	"213"
	"231"
	"312"
	"321"
	给定 n 和 k，返回第 k 个排列。
	*/
public:
	/*
	Times:O(n^2)
	Space:O(1)
	*/
	string getPermutation(int n, int k) {
		vector<int> fact(n + 1, 1);
		for (int i = 1; i <= n; i++)
		{
			fact[i] = fact[i - 1] * i;
		}
		string ans;
		vector<bool> used(n + 1);
		for (int i = 0; i < n; i++)
		{
			int cnt = fact[n - i - 1];
			for (int j = 1; j <= n; j++)
			{
				if (used[j]) continue;
				if (k > cnt)
				{
					k -= cnt;
				}
				else
				{
					ans += j + '0';
					used[j] = true;
					break;
				}
			}
		}
		return ans;
	}

};