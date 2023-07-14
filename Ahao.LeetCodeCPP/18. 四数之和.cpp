using namespace std;
#include<vector>
#include<algorithm>

/*
18. ����֮��

����һ���� n ��������ɵ����� nums ����һ��Ŀ��ֵ target �������ҳ���������������ȫ�������Ҳ��ظ�����Ԫ�� [nums[a], nums[b], nums[c], nums[d]] ����������Ԫ��Ԫ��һһ��Ӧ������Ϊ������Ԫ���ظ�����

0 <= a, b, c, d < n
a��b��c �� d ������ͬ
nums[a] + nums[b] + nums[c] + nums[d] == target
����԰� ����˳�� ���ش� ��
*/
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < nums.size(); j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int l = j + 1, r = nums.size() - 1;
				long sum = target - nums[i] - nums[j];
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



class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> quadruplets;
		if (nums.size() < 4) {
			return quadruplets;
		}
		sort(nums.begin(), nums.end());
		int length = nums.size();
		for (int i = 0; i < length - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
				break;
			}
			if ((long)nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
				continue;
			}
			for (int j = i + 1; j < length - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
					break;
				}
				if ((long)nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
					continue;
				}
				int left = j + 1, right = length - 1;
				while (left < right) {
					long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						quadruplets.push_back({ nums[i], nums[j], nums[left], nums[right] });
						while (left < right && nums[left] == nums[left + 1]) {
							left++;
						}
						left++;
						while (left < right && nums[right] == nums[right - 1]) {
							right--;
						}
						right--;
					}
					else if (sum < target) {
						left++;
					}
					else {
						right--;
					}
				}
			}
		}
		return quadruplets;
	}
};

