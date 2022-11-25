#include<vector>

using namespace std;


/*
1390. ������
����һ���������� nums�����㷵�ظ�������ǡ���ĸ���������Щ�����ĸ�����֮�͡�

��������в���������������������򷵻� 0 ��
*/
class Solution {
public:
	int sumFourDivisors(vector<int>& nums) {
		int res = 0;
		for (auto x : nums)
		{
			int sum = 0, cnt = 0;	//cnt �����ĸ���
			for (int i = 1; i * i < x; i++)
			{
				if (x % i == 0)
				{
					sum += i, cnt++;
					//����ƽ������ʱ��
					if (x / i != i) sum += x / i, cnt++;
				}
			}
			if (cnt == 4)
				res += sum;
		}
		return res;
	}
};