#include<vector>
#include <unordered_map>

using namespace std;


/*
347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
*/
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> hash;
		for (auto x : nums) hash[x]++;
		int n = nums.size();
		vector<int> s(n + 1, 0);
		for (auto p : hash) s[p.second]++;
		int i = n, t = 0;
		while (t < k) t += s[i--];
		vector<int> res;
		for (auto p : hash)
			if (p.second > i)
				res.push_back(p.first);

		return res;
	}
};