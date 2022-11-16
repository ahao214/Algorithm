#include<vector>
#include <unordered_map>

using namespace std;


/*
1577. ����ƽ�����������˻��ķ�����
���������������� nums1 �� nums2 �����㷵�ظ������¹����γɵ���Ԫ�����Ŀ������ 1 ������ 2 ����

���� 1����Ԫ�� (i, j, k) ����� nums1[i]^2 == nums2[j] * nums2[k] ���� 0 <= i < nums1.length �� 0 <= j < k < nums2.length
���� 2����Ԫ�� (i, j, k) ����� nums2[i]^2 == nums1[j] * nums1[k] ���� 0 <= i < nums2.length �� 0 <= j < k < nums1.length
*/
class Solution {
public:
	int work(vector<int>& a, vector<int>& b)
	{
		int res = 0;
		//��ϣ��
		unordered_map<long long, int> hash;
		for (int x : a) hash[(long long)x * x]++;
		for (int j = 0; j < b.size(); j++)
		{
			for (int k = j + 1; k < b.size(); k++)
				res += hash[(long long)b[j] * b[k]];
		}
		return res;
	}

	int numTriplets(vector<int>& nums1, vector<int>& nums2) {
		return work(nums1, nums2) + work(nums2, nums1);
	}
};
