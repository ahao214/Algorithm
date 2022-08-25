#include<vector>

using namespace std;


/*
1848. ��Ŀ��Ԫ�ص���С����
����һ���������� nums ���±� �� 0 ��ʼ �������Լ��������� target �� start �������ҳ�һ���±� i ������ nums[i] == target �� abs(i - start) ��С�� ��ע�⣺abs(x) ��ʾ x �ľ���ֵ��

���� abs(i - start) ��

��Ŀ���ݱ�֤ target ������ nums �С�
*/
class Solution {
public:
	int getMinDistance(vector<int>& nums, int target, int start) {
		int res = INT_MAX;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] == target)
				res = min(res, abs(i - start));
		return res;
	}
};
