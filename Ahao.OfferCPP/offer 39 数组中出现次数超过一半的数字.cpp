#include<vector>

using namespace std;


/*
offer 39 �����г��ִ�������һ�������
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
