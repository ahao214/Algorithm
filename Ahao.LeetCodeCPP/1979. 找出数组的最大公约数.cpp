#include<vector>
#include <algorithm>
#include <numeric>

using namespace std;


/*
1979. �ҳ���������Լ��

����һ���������� nums ���������������������С���� ���Լ�� ��

�������� ���Լ�� ���ܹ��������������������������
*/

class Solution {
public:
	int findGCD(vector<int>& nums) {
		int mx = *max_element(nums.begin(), nums.end());
		int mn = *min_element(nums.begin(), nums.end());
		return gcd(mx, mn);
	}

	//�����Լ��
	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}
};
