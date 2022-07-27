#include<vector>

using namespace std;


/*
offer 49 ³óÊı
*/
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0) return 0;
		int i2 = 0;
		int i3 = 0;
		int i5 = 0;
		int ugly[index];
		ugly[0] = 1;
		int i = 1;
		while (i < index)
		{
			int n2 = ugly[i2] * 2;
			int n3 = ugly[i3] * 3;
			int n5 = ugly[i5] * 5;
			int minValue = min(min(n2, n3), n5);
			ugly[i] = minValue;
			if (ugly[i2] * 2 == minValue) i2++;
			if (ugly[i3] * 3 == minValue) i3++;
			if (ugly[i5] * 5 == minValue) i5++;
			++i;
		}
		return ugly[index - 1];
	}
};
