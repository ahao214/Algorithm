#include<vector>
#include <set>

using namespace std;


/*
975. 奇偶跳

给定一个整数数组 A，你可以从某一起始索引出发，跳跃一定次数。在你跳跃的过程中，第 1、3、5... 次跳跃称为奇数跳跃，而第 2、4、6... 次跳跃称为偶数跳跃。

你可以按以下方式从索引 i 向后跳转到索引 j（其中 i < j）：

在进行奇数跳跃时（如，第 1，3，5... 次跳跃），你将会跳到索引 j，使得 A[i] <= A[j]，A[j] 是可能的最小值。如果存在多个这样的索引 j，你只能跳到满足要求的最小索引 j 上。
在进行偶数跳跃时（如，第 2，4，6... 次跳跃），你将会跳到索引 j，使得 A[i] >= A[j]，A[j] 是可能的最大值。如果存在多个这样的索引 j，你只能跳到满足要求的最小索引 j 上。
（对于某些索引 i，可能无法进行合乎要求的跳跃。）
如果从某一索引开始跳跃一定次数（可能是 0 次或多次），就可以到达数组的末尾（索引 A.length - 1），那么该索引就会被认为是好的起始索引。

返回好的起始索引的数量。
*/
class Solution {
public:
	int oddEvenJumps(vector<int>& arr) {
		int n = arr.size();
		vector<vector<int>> f(n, vector<int>(2));
		f[n - 1][0] = f[n - 1][1] = 1;
		int res = 1;
		set<vector<int>> S;
		S.insert({ arr[n - 1],n - 1 });
		for (int i = n - 2; i >= 0; i--)
		{
			auto it = S.lower_bound({ arr[i],-1 });
			if (it != S.end())
			{
				int j = (*it)[1];
				f[i][1] = f[j][0];
			}
			it = S.lower_bound({ arr[i],n });
			if (it != S.begin())
			{
				--it;
				it = S.lower_bound({ (*it)[0],-1 });
				int j = (*it)[1];
				f[i][0] = f[j][1];
			}
			S.insert({ arr[i],i });
			if (f[i][1]) res++;
		}
		return res;
	}
};