using namespace std;
#include<vector>
#include <algorithm>
#include <xiosbase>


//����
class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), ret = 0, x = nums[n / 2];
		for (int i = 0; i < n; i++) {
			ret += abs(nums[i] - x);
		}
		return ret;
	}
};


//����ѡ��
class Solution {
public:
	int quickSelect(vector<int>& nums, int left, int right, int index) {
		int q = randomPartition(nums, left, right);
		if (q == index) {
			return nums[q];
		}
		else {
			return q < index ? quickSelect(nums, q + 1, right, index) : quickSelect(nums, left, q - 1, index);
		}
	}

	inline int randomPartition(vector<int>& nums, int left, int right) {
		int i = rand() % (right - left + 1) + left;
		swap(nums[i], nums[right]);
		return partition(nums, left, right);
	}

	inline int partition(vector<int>& nums, int left, int right) {
		int x = nums[right], i = left - 1;
		for (int j = left; j < right; ++j) {
			if (nums[j] <= x) {
				swap(nums[++i], nums[j]);
			}
		}
		swap(nums[i + 1], nums[right]);
		return i + 1;
	}

	int minMoves2(vector<int>& nums) {
		srand(time(0));
		int n = nums.size(), x = quickSelect(nums, 0, n - 1, n / 2), ret = 0;
		for (int i = 0; i < n; ++i) {
			ret += abs(nums[i] - x);
		}
		return ret;
	}
};




/*
462. �����ƶ�����ʹ����Ԫ����� II
����һ���ǿ��������飬�ҵ�ʹ��������Ԫ������������С�ƶ���������ÿ���ƶ��ɽ�ѡ����һ��Ԫ�ؼ�1���1�� �����Լ�������ĳ������Ϊ10000��
*/
class Solution {
public:
	int minMoves2(vector<int>& nums) {
		int n = nums.size();
		nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
		int res = 0;
		for (auto x : nums) res += abs(x - nums[n / 2]);
		return res;
	}
};
