using namespace std;
#include<vector>
#include<algorithm>


class Solution {
	/*
	18. ����֮��
	����һ���� n ��������ɵ����� nums ����һ��Ŀ��ֵ target �������ҳ���������������ȫ�������Ҳ��ظ�����Ԫ�� [nums[a], nums[b], nums[c], nums[d]] ����������Ԫ��Ԫ��һһ��Ӧ������Ϊ������Ԫ���ظ�����

	0 <= a, b, c, d < n
	a��b��c �� d ������ͬ
	nums[a] + nums[b] + nums[c] + nums[d] == target
	����԰� ����˳�� ���ش� ��
	*/
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < nums.size(); j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int l = j + 1, r = nums.size() - 1;
				int sum = target - nums[i] - nums[j];
				while (l < r) {
					if (nums[l] + nums[r] == sum) {
						ans.push_back({ nums[i],nums[j],nums[l],nums[r] });
						while (l < r && nums[l] == nums[l + 1]) l++;
						while (l < r && nums[r] == nums[r - 1]) r--;
						l++, r--;
					}
					else if (nums[l] + nums[r] < sum) {
						l++;
					}
					else {
						r--;
					}
				}
			}
		}
		return ans;
	}
};

