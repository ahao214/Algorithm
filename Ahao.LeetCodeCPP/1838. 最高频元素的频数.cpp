#include<vector>
#include<algorithm>

using namespace std;




/*
1838. ���ƵԪ�ص�Ƶ��
Ԫ�ص� Ƶ�� �Ǹ�Ԫ����һ�������г��ֵĴ�����

����һ���������� nums ��һ������ k ����һ�������У������ѡ�� nums ��һ���±꣬�������±��ӦԪ�ص�ֵ���� 1 ��

ִ����� k �β����󣬷������������ƵԪ�ص� ������Ƶ�� ��
*/
class Solution {
public:
	int maxFrequency(vector<int>& nums, int k) {
		typedef long long LL;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<LL> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
		int res = 0;
		for (int i = 1, j = 1; i <= n; i++)
		{
			while ((i - j + 1ll) * nums[i - 1] - (s[i] - s[j - 1]) > k)
				j++;
			res = max(res, i - j + 1);
		}
		return res;
	}
};
