#include<vector>

using namespace std;


/*
260. ֻ����һ�ε����� III
����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ�
�ҳ�ֻ����һ�ε�������Ԫ�ء�����԰� ����˳�� ���ش𰸡�
*/
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int s = 0;
		for (auto x : nums) {
			s ^= x;
		}
		int k = 0;
		while (!(s >> k & 1)) k++;

		int s2 = 0;
		for (auto x : nums) {
			if (x >> k & 1) {
				s2 ^= x;
			}
		}
		return vector<int>({ s2,s ^ s2 });
	}
};