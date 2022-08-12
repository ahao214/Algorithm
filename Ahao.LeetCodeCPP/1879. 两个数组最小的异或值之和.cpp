#include<vector>

using namespace std;


/*
1879. ����������С�����ֵ֮��
���������������� nums1 �� nums2 �����ǳ��ȶ�Ϊ n ��

��������� ���ֵ֮�� Ϊ (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) ���±�� 0 ��ʼ����

�ȷ�˵��[1,2,3] �� [3,2,1] �� ���ֵ֮�� ���� (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4 ��
���㽫 nums2 �е�Ԫ���������У�ʹ�� ���ֵ֮�� ��С ��

���㷵����������֮��� ���ֵ֮�� ��
*/
class Solution {
public:
	int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), INF = 1e9;
		vector<int> f(1 << n, INF);
		f[0] = 0;
		for (int i = 1; i < 1 << n; i++)
		{
			int s = 0;
			for (int j = 0; j < n; j++)
			{
				if (i >> j & 1)
					s++;
			}
			for (int j = 0; j < n; j++)
			{
				if (i >> j & 1)
					f[i] = min(f[i], f[i - (1 << j)] + (nums2[j] ^ nums1[s - 1]));
			}
		}
		return f[(1 << n) - 1];
	}

};