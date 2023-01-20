#include<vector>

using namespace std;



/*
1524. 和为奇数的子数组数目

给你一个整数数组 arr 。请你返回和为 奇数 的子数组数目。

由于答案可能会很大，请你将结果对 10^9 + 7 取余后返回。
*/
class Solution {
public:
	int numOfSubarrays(vector<int>& arr) {
		long oddCount = 0, evenCount = 1;
		long M = 1e9 + 7;
		long presum = 0;
		long res = 0;
		for (int i = 0; i < arr.size(); i++) {
			presum += arr[i];
			if (presum % 2 == 0)
				res += oddCount;
			else
				res += evenCount;
			res %= M;

			if (presum % 2 == 0)
				evenCount += 1;
			else
				oddCount += 1;
		}
		return res;
	}
};
