#include<vector>
#include<algorithm>

using namespace std;


/*
976. �����ε�����ܳ�

������һЩ�����������ȣ���ɵ����� nums ������ ����������������ɵġ������Ϊ��������ε�����ܳ� ����������γ��κ������Ϊ��������Σ����� 0��
*/
class Solution {
public:
	int largestPerimeter(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = nums.size() - 1; i >= 2; i--)
		{
			int a = nums[i - 2], b = nums[i - 1], c = nums[i];
			if (a + b > c)
				return a + b + c;
		}
		return 0;
	}
};