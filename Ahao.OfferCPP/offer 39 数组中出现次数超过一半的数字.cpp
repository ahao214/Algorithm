#include<vector>

using namespace std;


/*
offer 39 数组中出现次数超过一半的数字
*/
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int ans = numbers[0];
		int count = 1;
		for (int i = 1; i < numbers.size(); ++i) {
			if (count > 0) {
				if (ans == numbers[i]) {
					count++;
				}
				else
				{
					count--;
				}
			}
			else {
				count++;
				ans = numbers[i];
			}
		}
		return ans;
	}
};
