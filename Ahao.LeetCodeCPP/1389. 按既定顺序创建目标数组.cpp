#include<vector>

using namespace std;


/*
1389. ���ȶ�˳�򴴽�Ŀ������
���������������� nums �� index������Ҫ�������¹��򴴽�Ŀ�����飺

Ŀ������ target ���Ϊ�ա�
�������ҵ�˳�����ζ�ȡ nums[i] �� index[i]���� target �����е��±� index[i] ������ֵ nums[i] ��
�ظ���һ����ֱ���� nums �� index �ж�û��Ҫ��ȡ��Ԫ�ء�
���㷵��Ŀ�����顣

��Ŀ��֤���ֲ���λ�����Ǵ��ڡ�
*/
class Solution {
public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> res;

		for (int i = 0; i < nums.size(); i++)
		{
			res.push_back(0);
			//���Ѿ��������������ƶ�
			for (int j = res.size() - 1; j > index[i]; j--)
			{
				res[j] = res[j - 1];
			}
			//�����ݲ��뵽������
			res[index[i]] = nums[i];
		}
		return res;
	}

	//ʹ��insert����
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> res;

		for (int i = 0; i < nums.size(); i++)
		{
			res.insert(res.begin() + index[i], nums[i]);
		}
		return res;
	}
};