#include<vector>
#include<algorithm>

using namespace std;


/*
1877. ������������Ժ͵���Сֵ
һ������ (a,b) �� ���Ժ� ���� a + b ��������Ժ� ��һ���������������� ���Ժ� ��

�ȷ�˵��������������� (1,5) ��(2,3) �� (4,4)��������Ժ� Ϊ max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8 ��
����һ������Ϊ ż�� n ������ nums �����㽫 nums �е�Ԫ�طֳ� n / 2 �����ԣ�ʹ�ã�

nums ��ÿ��Ԫ�� ǡ�� �� һ�� �����У���
������Ժ� ��ֵ ��С ��
�������������Ի��ֵķ����£�������С�� ������Ժ� ��
*/
class Solution {
public:
	int minPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0, j = nums.size() - 1; i < j; i++, j--)
			res = max(res, nums[i] + nums[j]);
		return res;
	}

};