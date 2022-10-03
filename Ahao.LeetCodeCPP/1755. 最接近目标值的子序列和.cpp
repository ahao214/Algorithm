#include<vector>
#include<algorithm>


using namespace std;




/*
1755. ��ӽ�Ŀ��ֵ�������к�
����һ���������� nums ��һ��Ŀ��ֵ goal ��

����Ҫ�� nums ��ѡ��һ�������У�ʹ������Ԫ���ܺ���ӽ� goal ��Ҳ����˵�����������Ԫ�غ�Ϊ sum ������Ҫ ��С�����Բ� abs(sum - goal) ��

���� abs(sum - goal) ���ܵ� ��Сֵ ��

ע�⣬�������������ͨ���Ƴ�ԭʼ�����е�ĳЩԪ�أ�����ȫ�����ޣ����γɵ����顣
*/
const int N = 2000010;
int q[N];
class Solution {
public:

	int n, cnt, g, ans;
	void dfs1(vector<int>& nums, int u, int s)
	{
		if (u == (n + 1) / 2)
		{
			q[cnt++] = s;
			return;
		}
		dfs1(nums, u + 1, s);
		dfs1(nums, u + 1, s + nums[u]);
	}

	void dfs2(vector<int>& nums, int u, int s)
	{
		if (u == n)
		{
			int left = 0, right = cnt - 1;
			while (left < right)
			{
				int mid = left + right + 1 >> 1;
				if (q[mid] + s <= g) left = mid;
				else right = mid - 1;
			}
			ans = min(ans, abs(q[right] + s - g));
			if (right + 1 < cnt)
			{
				ans = min(ans, abs(q[right + 1] + s - g));
			}
			return;
		}
		dfs2(nums, u + 1, s);
		dfs2(nums, u + 1, s + nums[u]);
	}

	int minAbsDifference(vector<int>& nums, int goal) {
		n = nums.size(), cnt = 0, g = goal, ans = INT_MAX;
		dfs1(nums, 0, 0);
		sort(q, q + cnt);
		dfs2(nums, (n + 1) / 2, 0);
		return ans;
	}
};

