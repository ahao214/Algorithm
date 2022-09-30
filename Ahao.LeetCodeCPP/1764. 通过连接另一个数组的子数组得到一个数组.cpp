#include<vector>

using namespace std;



/*
1764. ͨ��������һ�������������õ�һ������
����һ������Ϊ n �Ķ�ά�������� groups ��ͬʱ����һ���������� nums ��

���Ƿ���Դ� nums ��ѡ�� n �� ���ཻ �������飬ʹ�õ� i ���������� groups[i] ���±�� 0 ��ʼ����ȫ��ͬ������� i > 0 ����ô�� (i-1) ���������� nums �г��ֵ�λ���ڵ� i ��������ǰ�档��Ҳ����˵����Щ�������� nums �г��ֵ�˳����Ҫ�� groups ˳����ͬ��

���������ҳ������� n �������飬���㷵�� true �����򷵻� false ��

����������±�Ϊ k ��Ԫ�� nums[k] ���ڲ�ֹһ�������飬�ͳ���Щ�������� ���ཻ �ġ�������ָ����ԭ����������Ԫ����ɵ�һ�����С�
*/
class Solution {
public:
	bool check(vector<int>& gs, vector<int>& nums, int i)
	{
		int k = 0;
		for (int j = i; k < gs.size() && j < nums.size(); k++, j++)
		{
			if (gs[k] != nums[j])
				return false;
		}
		if (k != gs.size()) return false;
		return true;
	}

	bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
		for (int i = 0, k = 0; i < nums.size(); i++)
		{
			if (check(groups[k], nums, i))
			{
				i += groups[k].size() - 1;
				k++;
				if (k == groups.size()) return true;
			}
		}
		return false;
	}
};


