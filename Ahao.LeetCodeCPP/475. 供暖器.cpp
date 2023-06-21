#include<vector>
#include <algorithm>

using namespace std;


/*
475. 供暖器

冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
*/
class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		heaters.push_back(INT_MIN), heaters.push_back(INT_MAX);
		sort(heaters.begin(), heaters.end());
		int res = 0;
		for (auto& x : houses)
		{
			int left = 0, right = heaters.size() - 1;
			while (left < right)
			{
				int mid = (left + right) >> 1;
				if (heaters[mid] >= x) right = mid;
				else
					left = mid + 1;
			}
			res = max(res, (int)min(heaters[right] - 0ll - x, x - 0ll - heaters[right - 1]));
		}
		return res;
	}
};




class Solution {
public:
	bool check(int mid, vector<int>& houses, vector<int>& heaters)
	{
		for (int i = 0, j = 0; i < houses.size(); i++)
		{
			while (j < heaters.size() && abs(heaters[j] - houses[i]) > mid)
				j++;
			if (j >= heaters.size()) return false;
		}
		return true;
	}

	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int left = 0, right = INT_MAX;
		while (left < right)
		{
			int mid = (long long)(left + right) >> 1;
			if (check(mid, houses, heaters)) right = mid;
			else left = mid + 1;
		}
		return right;
	}
};