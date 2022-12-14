#include<vector>
#include <deque>

using namespace std;


/*
239. �����������ֵ
����һ���������� nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ��

���� ���������е����ֵ ��
*/
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> res;
		for (int i = 0, j = 0; i < nums.size(); i++)
		{
			while (!dq.empty() && nums[dq.front()] <= nums[i])
				dq.pop_front();
			dq.push_front(i);
			if (i - j + 1 > k)
			{
				if (dq.back() <= j) dq.pop_back();
				j++;
			}
			if (i - j + 1 == k) res.push_back(nums[dq.back()]);
		}
		return res;
	}
};