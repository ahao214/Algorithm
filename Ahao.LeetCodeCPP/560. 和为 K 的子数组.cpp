#include<vector>
#include <unordered_map>

using namespace std;


/*
560. ��Ϊ K ��������
����һ���������� nums ��һ������ k ������ͳ�Ʋ����ظ������к�Ϊ k ������������ĸ�����
*/
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> hash;
		hash[0] = 1;
		int res = 0, s = 0;
		for (auto x : nums)
		{
			s += x;
			res += hash[s - k];
			hash[s]++;
		}
		return res;
	}
};