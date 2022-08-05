#include<vector>

using namespace std;


/*
1909. ɾ��һ��Ԫ��ʹ�����ϸ����
����һ���±�� 0 ��ʼ���������� nums ����� ǡ�� ɾ�� һ�� Ԫ�غ����� �ϸ���� ����ô���㷵�� true �����򷵻� false ��������鱾���Ѿ����ϸ�����ģ�����Ҳ���� true ��

���� nums �� �ϸ���� �Ķ���Ϊ�����������±�� 1 <= i < nums.length ������ nums[i - 1] < nums[i] ��
*/
class Solution {
public:
	bool canBeIncreasing(vector<int>& nums) {
		for (int i = -1; i < (int)nums.size(); i++)
		{
			bool flag = false;
			int last = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				if (j == i) continue;
				if (nums[j] <= last) flag = true;
				last = nums[j];
			}
			if (!flag) return true;
		}
		return false;
	}
};