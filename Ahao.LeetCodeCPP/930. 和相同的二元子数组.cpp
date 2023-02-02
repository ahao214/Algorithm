#include<vector>
#include <unordered_map>

using namespace std;


/*
930. ����ͬ�Ķ�Ԫ������

����һ����Ԫ����nums ����һ������ goal ������ͳ�Ʋ������ж��ٸ���Ϊ goal��
�ǿ������顣

������ �������һ���������֡�
*/
class Solution {
public:
	int numSubarraysWithSum(vector<int>& nums, int goal) {
		int n = nums.size();
		vector<int> sum(n + 1, 0), f(n + 1, 0);
		for (int i = 0; i < n; i++)
			sum[i + 1] = sum[i] + nums[i];
		int res = 0;
		f[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (sum[i] >= goal) res += f[sum[i] - goal];
			f[sum[i]]++;
		}
		return res;
	}
};




/*
930. ����ͬ�Ķ�Ԫ������
*/
class Solution {
public:
	int numSubarraysWithSum(vector<int>& nums, int goal) {
		int n = nums.size();
		unordered_map<int, int> cnt;
		cnt[0]++;
		int res = 0;
		for (int i = 1, s = 0; i <= n; i++)
		{
			s += nums[i - 1];
			res += cnt[s - goal];
			cnt[s] ++;
		}
		return res;
	}
};
