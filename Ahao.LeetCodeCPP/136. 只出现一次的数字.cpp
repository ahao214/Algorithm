#include<vector>

using namespace std;


/*
136. ֻ����һ�ε�����
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬
����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
*/
//a ^ a = 0  0 ^ a = a 
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto x : nums)
			res ^= x;
		return res;
	}
};