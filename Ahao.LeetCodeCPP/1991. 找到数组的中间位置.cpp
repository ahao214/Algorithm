#include<vector>

using namespace std;


/*
1991. �ҵ�������м�λ��
����һ���±�� 0 ��ʼ���������� nums �������ҵ� ����� ���м�λ�� middleIndex ��Ҳ�������п����м�λ���±���С��һ������

�м�λ�� middleIndex ������ nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1] �������±ꡣ

��� middleIndex == 0 ����߲��ֵĺͶ���Ϊ 0 �����Ƶģ���� middleIndex == nums.length - 1 ���ұ߲��ֵĺͶ���Ϊ 0 ��

���㷵�������������� ����� �� middleIndex ������������������м�λ�ã����㷵�� -1 ��
*/
class Solution {
public:
	int findMiddleIndex(vector<int>& nums) {
		int n = nums.size();
		vector<int> s(n + 2);
		for (int i = 1; i <= n; i++)
			s[i] = s[i - 1] + nums[i - 1];
		for (int i = 1; i <= n; i++)
			if (s[i - 1] == s[n] - s[i])
				return i - 1;
		return -1;
	}
};
