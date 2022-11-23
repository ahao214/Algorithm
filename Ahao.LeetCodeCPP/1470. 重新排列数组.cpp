#include<vector>

using namespace std;

class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> ans(2 * n);
		for (int i = 0; i < n; i++) {
			ans[2 * i] = nums[i];
			ans[2 * i + 1] = nums[i + n];
		}
		return ans;
	}
};




/*
1470. ������������
����һ������ nums ���������� 2n ��Ԫ�أ��� [x1,x2,...,xn,y1,y2,...,yn] �ĸ�ʽ���С�

���㽫���鰴 [x1,y1,x2,y2,...,xn,yn] ��ʽ�������У��������ź�����顣
*/
class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> res;
		for (int i = 0; i < n; i++)
		{
			res.push_back(nums[i]);
			res.push_back(nums[i + n]);
		}
		return res;
	}
};