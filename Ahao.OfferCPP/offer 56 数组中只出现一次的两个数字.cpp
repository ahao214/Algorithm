#include<vector>


using namespace std;



/*
offer 56 数组中只出现一次的两个数字
*/
class Solution {
public:
	vector<int> FindNumsAppearOnce(vector<int>& array) {
		vector<int> ans;
		int s = 0;
		int a = 0, b = 0;
		for (auto i : array) s ^= i;
		int last1 = s & -s;
		for (auto i : array)
		{
			if (last1 & i) a ^= i;
		}

		b = s ^ a;
		if (a < b)
		{
			ans.push_back(a);
			ans.push_back(b);
		}
		else
		{
			ans.push_back(b);
			ans.push_back(a);
		}
		return ans;
	}
};
