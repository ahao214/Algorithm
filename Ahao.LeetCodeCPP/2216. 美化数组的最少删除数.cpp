#include<vector>
#include <stack>

using namespace std;


/*
2216. �������������ɾ����

����һ���±�� 0 ��ʼ���������� nums �����������������������Ϊ���� nums ��һ�� �������� ��

nums.length Ϊż��
���������� i % 2 == 0 ���±� i ��nums[i] != nums[i + 1] ������
ע�⣬������ͬ����Ϊ���������顣

����Դ� nums ��ɾ������������Ԫ�ء�����ɾ��һ��Ԫ��ʱ����ɾ��Ԫ���Ҳ������Ԫ�ؽ��������ƶ�һ����λ�����ȱ��������Ԫ�ؽ��ᱣ�� ���� ��

����ʹ nums ��Ϊ������������ɾ���� ���� Ԫ����Ŀ��
*/
class Solution {
public:
	int minDeletion(vector<int>& nums) {
		if (nums.empty())
			return 0;

		stack<int> stk;
		int index = 0, res = 0;
		stk.push(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			if (index % 2 == 0 && nums[i] != stk.top())
			{
				stk.push(nums[i]);
				index++;
			}
			else if (index % 2 == 0 && nums[i] == stk.top())
			{
				res++;
			}
			else
			{
				stk.push(nums[i]);
				index++;
			}
		}
		//stk������
		if (stk.size() % 2 != 0)
			res++;
		return res;
	}
};