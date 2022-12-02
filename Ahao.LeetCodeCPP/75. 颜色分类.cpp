#include<vector>
using namespace std;


/*
75. ��ɫ����
����һ��������ɫ����ɫ����ɫ���� n ��Ԫ�ص����� nums ��ԭ�ض����ǽ�������ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳�����С�

����ʹ������ 0�� 1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��

�����ڲ�ʹ�ÿ��sort����������½��������⡣
*/
class Solution {

public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	void sortColors(vector<int>& nums) {
		int i = 0, j = 0, k = nums.size() - 1;
		while (j <= k)
		{
			if (nums[j] == 0) swap(nums[i++], nums[j++]);
			else if (nums[j] == 2) swap(nums[j], nums[k--]);
			else j++;
		}
	}
};


/*
75. ��ɫ����
����һ��������ɫ����ɫ����ɫ���� n ��Ԫ�ص����� nums ��ԭ�ض����ǽ�������ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳�����С�

����ʹ������ 0�� 1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��

�����ڲ�ʹ�ÿ��sort����������½��������⡣
*/
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zero = 0, second = nums.size() - 1;
		for (int i = 0; i <= second; i++)
		{
			while (i < second && nums[i] == 2) swap(nums[i], nums[second--]);
			if (nums[i] == 0) swap(nums[zero++], nums[i]);
		}
	}
};