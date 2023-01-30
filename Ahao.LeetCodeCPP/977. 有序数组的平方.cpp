#include<vector>

using namespace std;


/*
977. ���������ƽ��

����һ���� �ǵݼ�˳�� ������������� nums������ ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ�� �ǵݼ�˳�� ����
*/
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n);
		for (int i = 0, j = n - 1, k = n - 1; i <= j;)
		{
			if (nums[i] * nums[i] > nums[j] * nums[j])
			{
				res[k] = nums[i] * nums[i];
				i++, k--;
			}
			else
			{
				res[k] = nums[j] * nums[j];
				j--, k--;
			}
		}
		return res;
	}
};