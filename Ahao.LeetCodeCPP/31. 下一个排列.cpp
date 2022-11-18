using namespace std;
#include<vector>



/*
31. ��һ������
���������һ�� ����  ���ǽ������г�Ա�����л�����˳�����С�

���磬arr = [1,2,3] ��������Щ���������� arr �����У�[1,2,3]��[1,3,2]��[3,1,2]��[2,3,1] ��
��������� ��һ������ ��ָ����������һ���ֵ����������С�����ʽ�أ����������������и������ֵ�˳���С����������һ�������У���ô����� ��һ������ �������������������������������Ǹ����С������������һ����������У���ô��������������Ϊ�ֵ�����С�����У�������Ԫ�ذ��������У���

���磬arr = [1,2,3] ����һ�������� [1,3,2] ��
���Ƶأ�arr = [2,3,1] ����һ�������� [3,1,2] ��
�� arr = [3,2,1] ����һ�������� [1,2,3] ����Ϊ [3,2,1] ������һ���ֵ����������С�
����һ���������� nums ���ҳ� nums ����һ�����С�

���� ԭ�� �޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣
*/
class Solution {	
public:
	void nextPermutation(vector<int>& nums) {
		int k = nums.size() - 1;
		while (k > 0 && nums[k - 1] >= nums[k])
			k--;
		if (k == 0) {
			//ԭ�������������е�,ֱ�ӷ�ת����
			reverse(nums.begin(), nums.end());
		}
		else {
			int t = nums.size() - 1;
			while (nums[t] <= nums[k - 1]) t--;
			swap(nums[t], nums[k - 1]);
			reverse(nums.begin() + k, nums.end());
		}
	}
};



class Solution{
public:
    void nextPermutation(vector<int>& nums) {
		for(int i = nums.size() - 1; i > 0;i--)
		{
			if(nums[i-1] < nums[i])
			{
				int j = i;
				while(j + 1 < nums.size() && nums[j + 1] > nums[i - 1]) j++;
				swap(nums[i-1],nums[j]);
				reverse(nums.begin() + 1,nums.end());
				return;
			}
		}
		reverse(nums.begin(),nums.end());
    }
};
