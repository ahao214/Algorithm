#include<vector>
#include <algorithm>

using namespace std;



/*
376. �ڶ�����
�����������֮��Ĳ��ϸ���������͸���֮�佻�棬���������г�Ϊ �ڶ����� ����һ���������ڵĻ�����������������������һ��Ԫ�ػ��ߺ���������Ԫ�ص�����Ҳ�����ڶ����С�

���磬 [1, 7, 4, 9, 2, 5] ��һ���ڶ����� ����Ϊ��ֵ (6, -3, 5, -7, 3) ������������ֵġ�

�෴��[1, 4, 7, 2, 5] �� [1, 7, 4, 5, 5] ���ǰڶ����У���һ����������Ϊ����ǰ������ֵ�����������ڶ�����������Ϊ�������һ����ֵΪ�㡣
������ ����ͨ����ԭʼ������ɾ��һЩ��Ҳ���Բ�ɾ����Ԫ������ã�ʣ�µ�Ԫ�ر�����ԭʼ˳��

����һ���������� nums ������nums����Ϊ�ڶ����е�������еĳ��� ��
*/
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		//ɾ����ͬ��Ԫ��
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		if (nums.size() <= 2) return nums.size();

		int res = 2;
		for (int i = 1; i + 1 < nums.size(); i++) {
			int a = nums[i - 1], b = nums[i], c = nums[i + 1];
			if (a<b && b>c) res++;
			else if (a > b && b < c) res++;
		}
		return res;
	}
};