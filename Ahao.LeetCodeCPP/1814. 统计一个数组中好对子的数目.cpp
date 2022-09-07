#include<vector>
#include<string>
#include <unordered_map>

using namespace std;


/*
1814. ͳ��һ�������кö��ӵ���Ŀ
����һ������ nums ��������ֻ�����Ǹ����������� rev(x) ��ֵΪ������ x ��������λ��ת�õ��Ľ�����ȷ�˵ rev(123) = 321 �� rev(120) = 21 �����ǳ����������������±�� (i, j) �� �õ� ��

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
���㷵�غ��±�Ե���Ŀ�����ڽ�����ܻ�ܴ��뽫����� 109 + 7 ȡ�� �󷵻ء�
*/
class Solution {
public:
	int countNicePairs(vector<int>& nums) {
		unordered_map<int, int> cnt;
		for (auto t : nums)
		{
			int x = t;
			string s = to_string(x);
			reverse(s.begin(), s.end());
			int y = stoi(s);
			cnt[x - y]++;
		}
		const int MOD = 1e9 + 7;
		int res = 0;
		for (auto [k, v] : cnt)
			res = (res + (long long)v * (v - 1) / 2) % MOD;
		return res;
	}
};

