#include<vector>
using namespace std;



/*
1822. ����Ԫ�ػ��ķ���
��֪���� signFunc(x) ������� x �����������ض�ֵ��

��� x ������������ 1 ��
��� x �Ǹ��������� -1 ��
��� x �ǵ��� 0 ������ 0 ��
����һ���������� nums ���� product Ϊ���� nums ������Ԫ��ֵ�ĳ˻���

���� signFunc(product) ��
*/
class Solution {
public:
	int sign(int x)
	{
		if (x > 0) return 1;
		if (x < 0) return -1;
		return 0;
	}

	int arraySign(vector<int>& nums) {
		int res = 1;
		for (auto x : nums)
			res *= sign(x);
		return res;
	}
};