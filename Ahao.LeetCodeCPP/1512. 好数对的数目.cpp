#include<vector>
#include <unordered_map>

using namespace std;


/*
1512. �����Ե���Ŀ
����һ���������� nums ��

���һ������ (i,j) ���� nums[i] == nums[j] �� i < j ���Ϳ�����Ϊ����һ�� ������ ��

���غ����Ե���Ŀ��
*/
class Solution {
public:
	/*
	ͳ��ÿ�����ֵĸ���
	*/
	int numIdenticalPairs(vector<int>& nums) {
		unordered_map<int, int> cnt;
		for (auto x : nums) cnt[x]++;
		int res = 0;
		for (auto [v, c] : cnt)
			res += c * (c - 1) / 2;
		return res;
	}
};