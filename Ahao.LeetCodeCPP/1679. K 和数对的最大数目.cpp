#include<vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*
1679. K �����Ե������Ŀ
����һ���������� nums ��һ������ k ��

ÿһ�������У�����Ҫ��������ѡ����Ϊ k ���������������������Ƴ����顣

��������Զ�����ִ�е�����������
*/
class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		unordered_map<int, int> hash;
		for (auto c : nums) hash[c]++;
		int res = 0;
		for (auto item : hash)
		{
			int x = item.first;
			int y = k - x;
			if (hash.count(x) && hash.count(y))
			{
				int cnt = min(hash[x], hash[y]);
				if (x == y) cnt /= 2;
				res += cnt;
				hash[x] -= cnt, hash[y] -= cnt;
			}
		}
		return res;
	}
};