#include<vector>
#include <stack>

using namespace std;


/*
456. 132 ģʽ
����һ���������� nums �������й��� n ��������132 ģʽ�������� ���������� nums[i]��nums[j] �� nums[k] ��ɣ���ͬʱ���㣺i < j < k �� nums[i] < nums[k] < nums[j] ��

��� nums �д��� 132 ģʽ�������� ������ true �����򣬷��� false ��
*/
class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int s = INT_MIN;
		stack<int> stk;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (nums[i] < s) return true;
			while (stk.size() && stk.top() <= nums[i])
			{
				s = max(s, stk.top());
				stk.pop();
			}
			stk.push(nums[i]);
		}
		return false;
	}
};