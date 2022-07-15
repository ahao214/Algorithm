#include<vector>

using namespace std;

class Solution {
	/*
	80. ɾ�����������е��ظ��� II
	����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ���������� ������ɾ����������³��ȡ�

	��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
	*/
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2) return nums.size();
		int idx = 1;
		for (int i = 2; i < nums.size(); i++)
		{
			if (nums[i] != nums[idx - 1])
			{
				nums[++idx] = nums[i];
			}
		}
		return idx + 1;
	}
};
