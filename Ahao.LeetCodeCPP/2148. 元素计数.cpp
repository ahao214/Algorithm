#include<vector>
#include<algorithm>

using namespace std;


/*
2148. Ԫ�ؼ���
����һ���������� nums ��ͳ�Ʋ������� nums ��ͬʱ���پ���һ���ϸ��СԪ�غ�һ���ϸ�ϴ�Ԫ�ص�Ԫ����Ŀ��
*/
class Solution {
public:
	//�жϴ�����Сֵ��С�����ֵ�����ֵĸ���
	int countElements(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res = 0;
		for (auto x : nums)
			if (x > nums[0] && x < nums.back())
				res++;
		return res;
	}

};