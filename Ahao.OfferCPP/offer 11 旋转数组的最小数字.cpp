#include<vector>

using namespace std;



/*
offer 11 旋转数组的最小数字
*/
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int left = 0, right = rotateArray.size() - 1;
		while (left < right)
		{
			if (rotateArray[left] < rotateArray[right])
			{
				return rotateArray[left];
			}
			int mid = (left + right) >> 1;
			if (rotateArray[mid] > rotateArray[right])
			{
				left = mid + 1;
			}
			else if (rotateArray[mid] < rotateArray[right]) {
				right = mid;
			}
			else {
				--right;
			}
		}
		return rotateArray[right];
	}
};