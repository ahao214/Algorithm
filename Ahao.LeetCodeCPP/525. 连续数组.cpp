#include<vector>
#include <unordered_map>

using namespace std;



/*
525. ��������
����һ������������nums , �ҵ�������ͬ������0��1 ������������飬�����ظ�������ĳ��ȡ�
*/
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		unordered_map<int, int> hash;
		hash[0] = -1;
		int res = 0, s = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			s += nums[i] ? 1 : -1;
			if (!hash.count(s)) hash[s] = i;
			else res = max(res, i - hash[s]);
		}
		return res;
	}
};
