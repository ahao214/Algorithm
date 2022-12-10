#include<vector>
#include <unordered_map>

using namespace std;



/*
454. ������� II
�����ĸ��������� nums1��nums2��nums3 �� nums4 �����鳤�ȶ��� n ����������ж��ٸ�Ԫ�� (i, j, k, l) �����㣺

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/
class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int, int> hash;
		for (auto n1 : nums1)
		{
			for (auto n2 : nums2)
				hash[n1 + n2]++;
		}
		int res = 0;
		for (auto n3 : nums3)
		{
			for (auto n4 : nums4)
				res += hash[-n3 - n4];
		}
		return res;
	}
};