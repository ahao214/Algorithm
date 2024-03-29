using namespace std;

#include<vector>


/*
4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
*/
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size() + nums2.size();
		if (n % 2 == 0) {
			int left = find(nums1, 0, nums2, 0, n / 2);
			int right = find(nums1, 0, nums2, 0, n / 2 + 1);
			return (left + right) / 2.0;
		}
		else {
			return find(nums1, 0, nums2, 0, n / 2 + 1);
		}
	}

	//找到数组中第K大的元素
	int find(vector<int>& num1, int i, vector<int>& num2, int j, int k) {
		if (num1.size() - i > num2.size() - j) {
			return find(num2, j, num1, i, k);
		}
		if (num1.size() == i)
			return num2[j + k - 1];
		if (k == 1)
			return min(num1[i], num2[j]);

		int idx1 = min((int)num1.size(), i + k / 2);
		int idx2 = j + k - k / 2;

		if (num1[idx1 - 1] < num2[idx2 - 1]) {
			return find(num1, idx1, num2, j, k - (idx1 - i));
		}
		else {
			return find(num1, i, num2, idx2, k - (idx2 - j));
		}
	}
};



/*
4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
*/
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int N1 = nums1.size();
		int N2 = nums2.size();
		if (N1 < N2) return findMedianSortedArrays(nums2, nums1);

		int low = 0, high = N2 * 2;
		while (low <= high)
		{
			int mid2 = (low + high) / 2;
			int mid1 = N1 + N2 - mid2;

			double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
			double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
			double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1) / 2];
			double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2) / 2];

			if (L1 > R2) low = mid2 + 1;
			else if (L2 > R1) high = mid2 - 1;
			else return (max(L1, L2) + min(R1, R2)) / 2;
		}
		return -1;
	}
};