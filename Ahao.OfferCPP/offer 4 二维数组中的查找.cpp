#include<vector>

using namespace std;



/*
offer 4 二维数组中的查找
*/
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty() || array[0].empty())
			return false;
		//记录右上角的坐标
		int i = 0, j = array[0].size() - 1;
		while (i <= array.size() - 1 && j >= 0)
		{
			if (array[i][j] == target)
			{
				return true;
			}
			else if (array[i][j] > target)
			{
				--j;
			}
			else
			{
				++i;
			}
		}
		return false;
	}
};