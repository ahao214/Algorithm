using namespace std;
#include<vector>

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int idx = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[idx]) {
				nums[++idx] = nums[i];
			}
		}
		return idx + 1;
	}
};



/*
26. ɾ�����������е��ظ���
����һ�� �������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��

������ĳЩ�����в��ܸı�����ĳ��ȣ����Ա��뽫�����������nums�ĵ�һ���֡����淶��˵�������ɾ���ظ���֮���� k ��Ԫ�أ���ô nums ��ǰ k ��Ԫ��Ӧ�ñ������ս����

�����ս������ nums ��ǰ k ��λ�ú󷵻� k ��
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int idx = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[idx]) {
				nums[++idx] = nums[i];
			}
		}
		return idx + 1;
	}
};



