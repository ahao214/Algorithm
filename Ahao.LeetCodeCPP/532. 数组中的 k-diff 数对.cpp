#include<vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


//��ϣ��
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		unordered_set<int> visited;
		unordered_set<int> res;
		for (int num : nums) {
			if (visited.count(num - k)) {
				res.emplace(num - k);
			}
			if (visited.count(num + k)) {
				res.emplace(num);
			}
			visited.emplace(num);
		}
		return res.size();
	}
};


//����+˫ָ��
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), y = 0, res = 0;
		for (int x = 0; x < n; x++) {
			if (x == 0 || nums[x] != nums[x - 1]) {
				while (y < n && (nums[y] < nums[x] + k || y <= x)) {
					y++;
				}
				if (y < n && nums[y] == nums[x] + k) {
					res++;
				}
			}
		}
		return res;
	}
};




/*
532. �����е� k-diff ����
����һ�����������һ������ k������Ҫ���������ҵ� ��ͬ�� k-diff ���ԣ������ز�ͬ�� k-diff ���� ����Ŀ��

���ｫ k-diff ���Զ���Ϊһ�������� (nums[i], nums[j])������������ȫ��������

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
ע�⣬|val| ��ʾ val �ľ���ֵ��
*/
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		int size = nums.size();
		int left = 0, right = 1, res = 0;
		sort(nums.begin(), nums.end());
		while (left < size && right < size)
		{
			if (left == right || (nums[right] - nums[left]) < k)
			{
				right++;
			}
			else if (nums[right] - nums[left] > k)
			{
				left++;
			}
			else
			{
				res++;
				left++;
				while (left < size && nums[left] == nums[left - 1])
				{
					left++;
				}
			}
		}
		return res;
	}
};
