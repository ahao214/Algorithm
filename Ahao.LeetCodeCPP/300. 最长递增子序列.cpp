#include<vector>

using namespace std;


/*
300. �����������
����һ���������� nums ���ҵ�������ϸ���������еĳ��ȡ�

���������������������������У�ɾ������ɾ���������е�Ԫ�ض�
���ı�����Ԫ�ص�˳��
���磬[3,6,2,7] ������ [0,3,1,6,2,2,7] �������С�
*/
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> f(n);
		for (int i = 0; i < n; i++)
		{
			f[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
					f[i] = max(f[i], f[j] + 1);
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
			res = max(res, f[i]);
		return res;
	}
};