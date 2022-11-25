#include<vector>

using namespace std;


/*
1389. 按既定顺序创建目标数组
给你两个整数数组 nums 和 index。你需要按照以下规则创建目标数组：

目标数组 target 最初为空。
按从左到右的顺序依次读取 nums[i] 和 index[i]，在 target 数组中的下标 index[i] 处插入值 nums[i] 。
重复上一步，直到在 nums 和 index 中都没有要读取的元素。
请你返回目标数组。

题目保证数字插入位置总是存在。
*/
class Solution {
public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> res;

		for (int i = 0; i < nums.size(); i++)
		{
			res.push_back(0);
			//将已经插入的数字向后移动
			for (int j = res.size() - 1; j > index[i]; j--)
			{
				res[j] = res[j - 1];
			}
			//将数据插入到数组中
			res[index[i]] = nums[i];
		}
		return res;
	}

	//使用insert函数
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> res;

		for (int i = 0; i < nums.size(); i++)
		{
			res.insert(res.begin() + index[i], nums[i]);
		}
		return res;
	}
};