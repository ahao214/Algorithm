using namespace std;
#include<vector>
#include <unordered_map>
#include <queue>


class Solution {
	/*
	15. ����֮��
	����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 �������ҳ����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣

	ע�⣺���в����԰����ظ�����Ԫ�顣
	*/
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			//ȥ��
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int l = i + 1, r = nums.size() - 1;
			int target = 0 - nums[i];
			while (l < r) {
				if (nums[l] + nums[r] == target) {
					res.push_back({ nums[i],nums[l],nums[r] });
					//ȥ��
					while (l < r && nums[l] == nums[l + 1]) l++;
					while (l < r && nums[r] == nums[r - 1]) r--;
					l++, r--;
				}
				else if (nums[l] + nums[r] < target) {
					l++;
				}
				else {
					r--;
				}
			}
		}
		return res;
	}
};

