#include<vector>
#include <numeric>

using namespace std;



/*
1031. 两个非重叠子数组的最大和

给出非负整数数组 A ，返回两个非重叠（连续）子数组中元素的最大和，子数组的长度分别为 L 和 M。（这里需要澄清的是，长为 L 的子数组可以出现在长为 M 的子数组之前或之后。）

从形式上看，返回最大的 V，而 V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) 并满足下列条件之一：

0 <= i < i + L - 1 < j < j + M - 1 < A.length, 或
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
*/

class Solution {
public:
	int work(vector<int>& nums, int a, int b)
	{
		int n = nums.size();
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++)
			s[i] = s[i - 1] + nums[i - 1];
		int res = 0;
		for (int i = a + b, maxa = 0; i <= n; i++)
		{
			maxa = max(maxa, s[i - b] - s[i - b - a]);
			res = max(res, s[i] - s[i - b] + maxa);
		}
		return res;
	}

	int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
		return max(work(nums, firstLen, secondLen), work(nums, secondLen, firstLen));
	}
};


class Solution {
public:
	int help(vector<int>& nums, int firstLen, int secondLen) {
		int suml = accumulate(nums.begin(), nums.begin() + firstLen, 0);
		int maxSumL = suml;
		int sumr = accumulate(nums.begin() + firstLen, nums.begin() + firstLen + secondLen, 0);
		int res = maxSumL + sumr;
		for (int i = firstLen + secondLen, j = firstLen; i < nums.size(); ++i, ++j) {
			suml += nums[j] - nums[j - firstLen];
			maxSumL = max(maxSumL, suml);
			sumr += nums[i] - nums[i - secondLen];
			res = max(res, maxSumL + sumr);
		}
		return res;
	}

	int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
		return max(help(nums, firstLen, secondLen), help(nums, secondLen, firstLen));
	}
};
