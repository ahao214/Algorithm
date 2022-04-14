using namespace std;
#include<vector>
#include <algorithm>

class Solution {
	/*
	16. ��ӽ�������֮��
	����һ������Ϊ n ���������� nums �� һ��Ŀ��ֵ target������� nums ��ѡ������������ʹ���ǵĺ��� target ��ӽ���

	�������������ĺ͡�

	�ٶ�ÿ������ֻ����ǡ��һ���⡣
	*/
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int res = nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			int l = i + 1, r = nums.size() - 1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == target) return sum;
				if (abs(sum - target) < abs(res - target))
					res = sum;
				if (sum < target)
					l++;
				else
					r--;
			}
		}
		return res;
	}
};
