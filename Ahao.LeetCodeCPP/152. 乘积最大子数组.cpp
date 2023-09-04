#include<vector>

using namespace std;


/*
152. �˻����������

����һ���������� nums �������ҳ������г˻����ķǿ����������飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻���

���������Ĵ���һ�� 32-λ ������

������ ����������������С�
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int res = nums[0];
		int f = nums[0], g = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int a = nums[i], fa = f * a, ga = g * a;
			f = max(a, max(fa, ga));
			g = min(a, min(fa, ga));
			res = max(res, f);
		}
		return res;
	}
};