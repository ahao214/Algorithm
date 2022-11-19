#include<vector>
#include <algorithm>
#include <unordered_map>

using namespace std;



/*
2007. 从双倍数组中还原原数组

一个整数数组 original 可以转变成一个 双倍 数组 changed ，转变方式为将 original 中每个元素 值乘以 2 加入数组中，然后将所有元素 随机打乱 。

给你一个数组 changed ，如果 change 是 双倍 数组，那么请你返回 original数组，否则请返回空数组。original 的元素可以以 任意 顺序返回。
*/
class Solution {
public:
	vector<int> findOriginalArray(vector<int>& changed) {
		int size = changed.size();
		if (size % 2)	// 元素个数是奇数个 直接返回空
		{
			return {};
		}
		sort(changed.begin(), changed.end());
		unordered_map<int, int> dict;
		for (auto num : changed)
		{
			dict[num]++;
		}

		vector<int> res;
		for (auto num : changed)
		{
			if (dict[num])
			{
				dict[num]--;
				int twice = num * 2;
				if (dict[twice] > 0)
				{
					dict[twice]--;
					res.push_back(num);
				}
				else
				{
					return {};
				}
			}
		}

		return res;
	}
};