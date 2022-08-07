#include<vector>
#include<algorithm>

using namespace std;


/*
1913. ��������֮������˻���
�������� (a, b) �� (c, d) ֮��� �˻��� ����Ϊ (a * b) - (c * d) ��

���磬(5, 6) �� (2, 7) ֮��ĳ˻����� (5 * 6) - (2 * 7) = 16 ��
����һ���������� nums ��ѡ���ĸ� ��ͬ�� �±� w��x��y �� z ��ʹ���� (nums[w], nums[x]) �� (nums[y], nums[z]) ֮��� �˻��� ȡ�� ���ֵ ��

���������ַ�ʽȡ�õĳ˻����е� ���ֵ ��
*/
class Solution {
public:
	int maxProductDifference(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
	}
};

