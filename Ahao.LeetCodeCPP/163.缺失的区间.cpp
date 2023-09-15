#include<vector>
#include<string>
#include <chrono>

using namespace std;


/*
163.È±Ê§µÄÇø¼ä
*/
class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int high) {
		vector<string> res;
		nums.push_back(upper + 1);
		int last = lower - 1;
		for (auto num : nums)
		{
			if (num - last == 2)
			{
				res.push_back(to_string(last + 1));
			}
			else if (num - last > 2) {
				res.push_back(to_string(last + 1) + "->" + to_string(num - 1));
			}
			last = num;
		}
		return res;
	}
};