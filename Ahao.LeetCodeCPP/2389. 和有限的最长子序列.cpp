#include<vector>
#include <algorithm>

using namespace std;


/*
2389. 和有限的最长子序列
给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。

返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于等于 queries[i] 的 子序列 的 最大 长度  。

子序列 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。
*/
class Solution {
public:
	vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i) {
			nums[i] += nums[i - 1];
		}
		vector<int> res;
		for (auto& q : queries) {
			int index = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
			res.push_back(index);
		}
		return res;
	}
};


class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> f(n + 1);
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i] + nums[i];
        }
        vector<int> answer(m);
        for (int i = 0; i < m; i++) {
            answer[i] = upper_bound(f.begin(), f.end(), queries[i]) - f.begin() - 1;
        }
        return answer;
    }
};
