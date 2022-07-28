#include<vector>
#include<string>
#include<algorithm>

using namespace std;


/*
offer 45 把数组排成最小的数
*/
class Solution {
public:
	string PrintMinNumber(vector<int> nums) {
		string res;
		if (nums.empty()) return res;
		vector<string> strs;
		for (auto n : nums)
		{
			strs.push_back(to_string(n));
		}

		sort(strs.begin(), strs.end(), compare);

		for (auto i : strs)
		{
			res.append(i);
		}
		return res;
	}

	static int compare(string& a, string& b)
	{
		string ab = a + b;
		string ba = b + a;
		return ab < ba;
	}
};

