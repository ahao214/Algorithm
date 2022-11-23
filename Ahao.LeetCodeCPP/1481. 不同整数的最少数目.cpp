#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/*
1481. 不同整数的最少数目
给你一个整数数组 arr 和一个整数 k 。现需要从数组中恰好移除 k 个元素，请找出移除后数组中不同整数的最少数目。
*/
class Solution {
public:
	//统计每个数出现的次数,先移除出现次数最少的数字
	//排序+贪心
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
		//哈希表
		unordered_map<int, int> hash;
		for (auto x : arr) hash[x]++;

		vector<int> cnt;
		for (auto x : hash) cnt.push_back(x.second);
		sort(cnt.begin(), cnt.end());

		int res = cnt.size();
		for (auto c : cnt)
		{
			if (k >= c)
			{
				k -= c;
				res--;
			}
			else {
				break;
			}
		}
		return res;
	}
};