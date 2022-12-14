using namespace std;

#include<vector>


/*
4. Ѱ�����������������λ��
����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��

�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��
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

	//�ҵ������е�K���Ԫ��
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