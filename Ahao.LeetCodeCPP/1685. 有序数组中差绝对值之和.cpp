#include<vector>

using namespace std;



/*
1685. ���������в����ֵ֮��
����һ�� �ǵݼ� ������������ nums ��

���㽨��������һ���������� result������ nums ������ͬ����result[i] ���� nums[i] ����������������Ԫ�ز�ľ���ֵ֮�͡�

���仰˵�� result[i] ���� sum(|nums[i]-nums[j]|) ������ 0 <= j < nums.length �� j != i ���±�� 0 ��ʼ����
*/
class Solution {
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		int n = nums.size();
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
		vector<int> res;
		for (int i = 1; i <= n; i++)
		{
			int left = i * nums[i - 1] - s[i];
			int right = s[n] - s[i] - nums[i - 1] * (n - i);
			res.push_back(left + right);
		}
		return res;
	}
};