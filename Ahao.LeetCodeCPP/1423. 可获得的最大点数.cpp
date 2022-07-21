#include<vector>
#include <numeric>

using namespace std;


/*
1423. 可获得的最大点数
时间O(N) 空间O(1)
*/

class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int size = cardPoints.size();
		int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
		if (size <= k)
		{
			return sum;
		}

		int minValue = INT_MAX, currentSum = 0, left = 0;
		for (int right = 0; right < size; right++)
		{
			currentSum += cardPoints[right];
			int windowSize = right - left + 1;
			if (windowSize == size - k)
			{
				minValue = min(minValue, currentSum);
				currentSum -= cardPoints[left];
				left++;
			}
		}
		return sum - minValue;

	}
};