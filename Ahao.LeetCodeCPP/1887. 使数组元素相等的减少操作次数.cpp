#include<vector>
#include<algorithm>


using namespace std;


/*
1887. ʹ����Ԫ����ȵļ��ٲ�������
����һ���������� nums �����Ŀ������ nums �е�����Ԫ����ȡ����һ�μ��ٲ�����Ҫ��������ļ������裺

�ҳ� nums �е� ��� ֵ�������ֵΪ largest ��ȡ���±� i ���±�� 0 ��ʼ������������ж��Ԫ�ض������ֵ����ȡ��С�� i ��
�ҳ� nums �е� ��һ����� ֵ�����ֵ �ϸ�С�� largest ����Ϊ nextLargest ��
�� nums[i] ���ٵ� nextLargest ��
����ʹ nums �е�����Ԫ����ȵĲ���������
*/
class Solution {
public:
	int reductionOperations(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 1, s = 0; i < nums.size(); i++)
		{
			if (nums[i] != nums[i - 1])
				s++;
			res += s;
		}
		return res;
	}
};