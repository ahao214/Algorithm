#include<vector>
using namespace std;


/*
75. 颜色分类
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。
*/
class Solution {

public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	void sortColors(vector<int>& nums) {
		int i = 0, j = 0, k = nums.size() - 1;
		while (j <= k)
		{
			if (nums[j] == 0) swap(nums[i++], nums[j++]);
			else if (nums[j] == 2) swap(nums[j], nums[k--]);
			else j++;
		}
	}
};


/*
75. 颜色分类
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。
*/
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zero = 0, second = nums.size() - 1;
		for (int i = 0; i <= second; i++)
		{
			while (i < second && nums[i] == 2) swap(nums[i], nums[second--]);
			if (nums[i] == 0) swap(nums[zero++], nums[i]);
		}
	}
};