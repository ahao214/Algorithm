#include<vector>

using namespace std;



/*
1863. �ҳ������Ӽ�������ܺ������
һ������� ����ܺ� ����Ϊ����������Ԫ�ذ�λ XOR �Ľ�����������Ϊ �� ��������ܺ�Ϊ 0 ��

���磬���� [2,5,6] �� ����ܺ� Ϊ 2 XOR 5 XOR 6 = 1 ��
����һ������ nums ��������� nums ��ÿ�� �Ӽ� �� ����ܺ� �����㲢������Щֵ���֮ �� ��

ע�⣺�ڱ����У�Ԫ�� ��ͬ �Ĳ�ͬ�Ӽ�Ӧ ��� ������

���� a ������ b ��һ�� �Ӽ� ��ǰ�������ǣ��� b ɾ��������Ҳ���ܲ�ɾ����Ԫ���ܹ��õ� a ��
*/
class Solution {
public:
	int subsetXORSum(vector<int>& nums) {
		int n = nums.size();
		int res = 0;
		for (int i = 0; i < 1 << n; i++)
		{
			int s = 0;
			for (int j = 0; j < n; j++)
			{
				if (i >> j & 1)
					s ^= nums[j];
			}
			res += s;
		}
		return res;
	}
};



