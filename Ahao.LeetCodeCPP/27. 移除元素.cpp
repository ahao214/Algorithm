using namespace std;
#include<vector>;


class Solution {
	/*
	27. �Ƴ�Ԫ��
	����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ����val��Ԫ�أ��������Ƴ���������³��ȡ�
	��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢ԭ���޸��������顣
	Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
	*/
public:
	int removeElement(vector<int>& nums, int val) {
		int idx = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				nums[idx++] = nums[i];
			}
		}
		return idx;
	}
};
