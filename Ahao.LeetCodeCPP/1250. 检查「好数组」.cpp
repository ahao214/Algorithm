#include<vector>
#include <numeric>

using namespace std;

/*
1250. ��顸�����项

����һ������������ nums������Ҫ������ѡһЩ�Ӽ���Ȼ���Ӽ���ÿһ��������һ�� ������������������ǵĺ͡�

����úͽ��Ϊ 1����ôԭ�������һ���������项���򷵻� True�������뷵�� False��
*/

class Solution {
public:
	bool isGoodArray(vector<int>& nums) {
		int divisor = nums[0];
		for (int num : nums) {
			divisor = gcd(divisor, num);
			if (divisor == 1) {
				break;
			}
		}
		return divisor == 1;
	}

	//�����Լ��
	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}

};
