#include<vector>

using namespace std;



/*
offer 21 调整数组顺序使奇数位于偶数前面(一)
*/
class Solution {
public:
	vector<int> reOrderArray(vector<int>& array) {
		if (array.empty())
			return array;
		vector<int> res;
		for (auto it : array)
		{
			if (it % 2 == 1)
				res.push_back(it);
		}
		for (auto it : array)
		{
			if (it % 2 == 0)
				res.push_back(it);
		}
		return res;
	}
};