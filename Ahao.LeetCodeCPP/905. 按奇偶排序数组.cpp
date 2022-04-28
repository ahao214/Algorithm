using namespace std;
#include<vector>

//����һ�����α���
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		vector<int> res;
		for (auto& num : nums) {
			if (num % 2 == 0) {
				res.push_back(num);
			}
		}
		for (auto& num : nums) {
			if (num % 2 == 1) {
				res.push_back(num);
			}
		}
		return res;
	}
};


//��������˫ָ�� + һ�α���
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n);
		int left = 0, right = n - 1;
		for (auto& num : nums) {
			if (num % 2 == 0) {
				res[left++] = num;
			}
			else {
				res[right--] = num;
			}
		}
		return res;
	}
};


//��������ԭ�ؽ���
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			while (left < right and nums[left] % 2 == 0) {
				left++;
			}
			while (left < right and nums[right] % 2 == 1) {
				right--;
			}
			if (left < right) {
				swap(nums[left++], nums[right--]);
			}
		}
		return nums;
	}
};
