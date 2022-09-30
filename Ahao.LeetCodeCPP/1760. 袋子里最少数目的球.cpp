#include<vector>

using namespace std;


/*
1760. ������������Ŀ����
����һ���������� nums ������ nums[i] ��ʾ�� i �������������Ŀ��ͬʱ����һ������ maxOperations ��

����Խ������²������� maxOperations �Σ�

ѡ������һ�����ӣ��������������ֵ� 2 ���µĴ����У�ÿ�������ﶼ�� ������ ����
�ȷ�˵��һ���������� 5 ��������԰����Ƿֵ������´�����ֱ��� 1 ���� 4 ���򣬻��߷ֱ��� 2 ���� 3 ����
��Ŀ����ǵ�������������Ŀ�� ���ֵ ������Ҫ ��С�� ������

���㷵�ؽ����������������С������
*/
class Solution {
public:
	vector<int> arr;
	int m;
	bool check(int mid)
	{
		int res = 0;
		for (auto k : arr)
		{
			res += (k + mid - 1) / mid - 1;
			if (res > m) return false;
		}
		return true;
	}

	int minimumSize(vector<int>& nums, int maxOperations) {
		arr = nums, m = maxOperations;
		int left = 1, right = 1e9;
		while (left < right)
		{
			int mid = left + right >> 1;
			if (check(mid)) right = mid;
			else left = mid + 1;
		}
		return right;
	}
};