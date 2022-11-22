#include<vector>
#include <unordered_map>

using namespace std;


/*
1497. 检查数组对是否可以被 k 整除
给你一个整数数组 arr 和一个整数 k ，其中数组长度是偶数，值为 n 。

现在需要把数组恰好分成 n / 2 对，以使每对数字的和都能够被 k 整除。

如果存在这样的分法，请返回 True ；否则，返回 False 。
*/
class Solution {
public:
	/*
	余数是0 1 2 3 4 5 6...k-3 k-2 k-1
	数组中余数是0的数字只能和余数是0的数字配对
	数组中余数是1的数字只能和余数是k-1的数字配对
	数组中余数是2的数字只能和余数是k-2的数字配对
	数组中余数是3的数字只能和余数是k-3的数字配对
	*/
	bool canArrange(vector<int>& arr, int k) {
		unordered_map<int, int> cnt;	//记录每个余数出现的个数
		for (auto x : arr)
			cnt[(x % k + k) % k]++;
		if (cnt[0] % 2) return false;
		for (int i = 1; i < k; i++)
		{
			while (cnt[i])
			{
				cnt[i]--;
				if (cnt[k - i] <= 0)
					return false;
				cnt[k - i]--;
			}
		}
		return true;
	}
};
