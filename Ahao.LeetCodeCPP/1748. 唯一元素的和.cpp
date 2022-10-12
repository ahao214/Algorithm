#include<vector>
#include<unordered_map>

using namespace std;



/*
1748. ΨһԪ�صĺ�
����һ���������� nums ��������ΨһԪ������Щֻ���� ǡ��һ�� ��Ԫ�ء�

���㷵�� nums ��ΨһԪ�ص� �� ��
*/
class Solution {
public:
	int sumOfUnique(vector<int>& nums) {
		unordered_map<int, int> hash;
		for (auto x : nums) hash[x]++;
		int res = 0;
		for (auto [k, v] : hash)
			if (v == 1)
				res += k;
		return res;
	}
};