#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/*
954. 二倍数对数组

给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 “对于每个 0 <= i < len(arr) / 2，都有 arr[2 * i + 1] = 2 * arr[2 * i]” 时，返回 true；否则，返回 false。
*/
class Solution {
public:
	bool canReorderDoubled(vector<int>& arr) {
		int n = arr.size(), cnt = 0;
		sort(arr.begin(), arr.end());
		unordered_map<int, int> mp;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] < 0 && mp.count(arr[i] * 2))
			{
				if (--mp[arr[i] * 2] == 0)mp.erase(arr[i] * 2);
				cnt++;
			}
			else if (arr[i] >= 0 && arr[i] % 2 == 0 && mp.count(arr[i] / 2))
			{
				if (--mp[arr[i] / 2] == 0)mp.erase(arr[i] / 2);
				cnt++;
			}
			else
			{
				mp[arr[i]]++;
			}
		}

		return cnt == n / 2;
	}
};
