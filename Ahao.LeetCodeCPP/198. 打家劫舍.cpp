#include<vector>

using namespace std;

/*
198. ��ҽ���
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int rob = nums[0], norob = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			int robTmp = rob, norobTmp = norob;
			norob = max(robTmp, norobTmp);
			rob = norobTmp + nums[i];
		}
		return max(rob, norob);
	}
};



/*
198. ��ҽ���
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�
ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ
��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ��
����������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬
������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		//f[i]��ʾ��ǰi������ѡ�����в�ѡnums[i]��ѡ�������ֵ
		//g[i]��ʾ��ǰi������ѡ������ѡ��nums[i]��ѡ�������ֵ
		vector<int> f(n + 1), g(n + 1);
		for (int i = 1; i <= n; i++)
		{
			f[i] = max(f[i - 1], g[i - 1]);
			g[i] = nums[i - 1] + f[i - 1];
		}
		return max(f[n], g[n]);
	}
};