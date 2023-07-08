#include<vector>

using namespace std;




/*
315. �����Ҳ�С�ڵ�ǰԪ�صĸ���

����һ���������� nums ����Ҫ�󷵻�һ�������� counts ������ counts �и����ʣ� counts[i] ��ֵ��  nums[i] �Ҳ�С�� nums[i] ��Ԫ�ص�������
*/
class Solution {
public:
	int n = 20001;
	vector<int> tr;
	int lowbit(int x)
	{
		return x & -x;
	}

	int query(int x)
	{
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}

	void add(int x, int v)
	{
		for (int i = x; i <= n; i += lowbit(i))
			tr[i] += v;
	}

	vector<int> countSmaller(vector<int>& nums) {
		tr.resize(n + 1);
		vector<int> res(nums.size());
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			int x = nums[i] + 10001;
			res[i] = query(x - 1);
			add(x, 1);
		}
		return res;
	}
};