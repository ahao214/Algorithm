#include<vector>
#include <unordered_map>

using namespace std;



/*
974. �Ϳɱ� K ������������

����һ���������� nums ��һ������ k ����������Ԫ��֮�Ϳɱ� k �����ģ��������ǿգ� ������ ����Ŀ��

������ ������� ���� ���֡�
*/
class Solution {
public:
	int subarraysDivByK(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
		unordered_map<int, int> cnt;
		cnt[0]++;
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			int r = (s[i] % k + k) % k;
			res += cnt[r];
			cnt[r]++;
		}
		return res;
	}
};