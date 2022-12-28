#include<vector>

using namespace std;



/*
215. �����еĵ�K�����Ԫ��
������������ nums ������ k���뷵�������е� k ������Ԫ�ء�

��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
*/
class Solution {
	int partition(vector<int>& nums, int left, int right)
	{
		int pivot = nums[right], p = left;
		for (int i = left; i < right; i++)
		{
			if (nums[i] < pivot)
			{
				swap(nums[i], nums[p]);
				p++;
			}
		}
		swap(nums[p], nums[right]);
		return p;
	}

	void helper(vector<int>& nums, int left, int right, int k)
	{
		if (left >= right)
		{
			return;
		}
		int position = partition(nums, left, right);
		if (position == nums.size() - k)
			return;
		if (position < nums.size() - k)
			helper(nums, position + 1, right, k);
		else
			helper(nums, left, position - 1, k);
	}

public:
	int findKthLargest(vector<int>& nums, int k) {
		helper(nums, 0, nums.size() - 1, k);
		return nums[nums.size() - k];
	}
};