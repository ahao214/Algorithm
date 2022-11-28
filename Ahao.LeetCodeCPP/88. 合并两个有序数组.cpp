#include<vector>

using namespace std;

/*
88. �ϲ�������������
���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��

���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�

ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��
*/
class Solution {
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int idx = m + n - 1;
		int i = m - 1, j = n - 1;
		while (i >= 0 && j >= 0)
		{
			if (nums1[i] >= nums2[j])
				nums1[idx--] = nums1[i--];
			else
				nums1[idx--] = nums2[j--];
		}
		while (j >= 0)
			nums1[idx--] = nums2[j--];
	}
};
