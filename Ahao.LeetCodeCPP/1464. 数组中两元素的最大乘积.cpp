#include<vector>
#include<algorithm>

using namespace std;


/*
1464. ��������Ԫ�ص����˻�
����һ���������� nums������ѡ�������������ͬ�±� i �� j��ʹ (nums[i]-1)*(nums[j]-1) ȡ�����ֵ��

������㲢���ظ�ʽ�����ֵ��
*/
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return (nums.back() - 1) * (nums[nums.size() - 2] - 1);
	}
};

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int a = nums[0], b = nums[1];
		if (a < b) {
			swap(a, b);
		}
		for (int i = 2; i < nums.size(); i++) {
			if (nums[i] > a) {
				b = a;
				a = nums[i];
			}
			else if (nums[i] > b) {
				b = nums[i];
			}
		}
		return (a - 1) * (b - 1);
	}
};


class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int res = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < i; j++)
				res = max(res, (nums[i] - 1) * (nums[j] - 1));
		}
		return res;
	}
};