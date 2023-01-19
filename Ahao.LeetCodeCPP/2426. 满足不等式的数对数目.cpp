#include<vector>

using namespace std;


/*
2426. ���㲻��ʽ��������Ŀ

���������±�� 0 ��ʼ���������� nums1 �� nums2 ����������Ĵ�С��Ϊ n ��ͬʱ����һ������ diff ��ͳ���������������� ���� (i, j) ��

0 <= i < j <= n - 1 ��
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
���㷵������������ ������Ŀ ��
*/
using LL = long long;
class Solution {
	LL res = 0;
	LL diff;
public:
	long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
		int n = nums1.size();
		this->diff = diff;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			arr[i] = nums1[i] - nums2[i];
		}
		helper(arr, 0, arr.size() - 1);
		return res;
	}

	void helper(vector<int>& arr, int a, int b)
	{
		if (a == b)
			return;
		int mid = a + (b - a) / 2;
		helper(arr, a, mid);
		helper(arr, mid + 1, b);

		int i = a;
		for (int j = mid + 1; j <= b; j++)
		{
			while (i <= mid && arr[i] <= arr[j] + diff)
				i++;
			res += i - a;
		}

		inplace_merge(arr.begin() + a, arr.begin() + mid + 1, arr.begin() + b + 1);

	}
};

