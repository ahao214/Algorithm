#include<vector>

using namespace std;




/*
offer 14 МєЩўзг
*/
class Solution {
public:
	int cutRope(int number) {
		if (number < 2)
			return 0;
		if (number == 2)
			return 1;
		if (number == 3)
			return 2;
		vector<int> res(number + 1);
		res[0] = 0;
		res[1] = 1;
		res[2] = 2;
		res[3] = 3;
		for (int i = 4; i <= number; ++i)
		{
			int maxValue = 0;
			for (int j = 1; j <= i / 2; ++j)
			{
				int tmp = res[j] * res[i - j];
				maxValue = max(tmp, maxValue);
				res[i] = maxValue;
			}
		}
		return res[number];
	}
};

