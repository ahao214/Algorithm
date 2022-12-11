#include<vector>

using namespace std;


/*
1827. ���ٲ���ʹ�������
����һ���������� nums ���±�� 0 ��ʼ����ÿһ�β����У������ѡ��������һ��Ԫ�أ����������� 1 ��

�ȷ�˵����� nums = [1,2,3] �������ѡ������ nums[1] �õ� nums = [1,3,3] ��
���㷵��ʹ nums �ϸ���� �� ���� ����������

���ǳ����� nums �� �ϸ������ ����������������е� 0 <= i < nums.length - 1 ���� nums[i] < nums[i+1] ��һ������Ϊ 1 ���������ϸ������һ�����������
*/
class Solution {
public:
	int minOperations(vector<int>& nums) {
		int res = 0, last = 0;
		for (auto x : nums)
		{
			int cur = max(last + 1, x);
			res += cur - x;
			last = cur;
		}
		return res;
	}
};


class Solution {
public:
	int minOperations(vector<int>& nums) {
		int pre = nums[0] - 1, res = 0;
		for (int num : nums) {
			pre = max(pre + 1, num);
			res += pre - num;
		}
		return res;
	}
};