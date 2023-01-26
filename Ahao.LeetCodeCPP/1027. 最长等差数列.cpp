#include<vector>
#include<unordered_map>


using namespace std;


/*
1027. ��Ȳ�����

����һ���������� nums������ nums ����Ȳ������еĳ��ȡ�

����һ�£�nums ����������һ���б� nums[i1], nums[i2], ..., nums[ik] ���� 0 <= i1 < i2 < ... < ik <= nums.length - 1��������� seq[i+1] - seq[i]( 0 <= i < seq.length - 1) ��ֵ����ͬ����ô���� seq �ǵȲ�ġ�
*/
class Solution {
public:
	int longestArithSeqLength(vector<int>& nums) {
		int n = nums.size();
		vector<unordered_map<int, int>> f(n);

		int res = 2;
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < i; k++)
			{
				int j = nums[k] - nums[i];
				f[i][j] = max(f[i][j], 2);
				if (f[k].count(j))
				{
					f[i][j] = max(f[i][j], f[k][j] + 1);
					res = max(res, f[i][j]);
				}
			}
		}
		return res;
	}
};