#include<vector>

using namespace std;


/*
1911. ��������н����
һ���±�� 0 ��ʼ������� ����� ����Ϊ ż�� �±괦Ԫ��֮ �� ��ȥ ���� �±괦Ԫ��֮ �� ��

�ȷ�˵������ [4,2,5,3] �Ľ����Ϊ (4 + 5) - (2 + 3) = 4 ��
����һ������ nums �����㷵�� nums �����������е� ������ �������е��±� ���� �� 0 ��ʼ��ţ���

һ������� ������ �Ǵ�ԭ������ɾ��һЩԪ�غ�Ҳ����һ��Ҳ��ɾ����ʣ��Ԫ�ز��ı�˳����ɵ����顣�ȷ�˵��[2,7,4] �� [4,2,3,7,2,1,4] ��һ�������У��Ӵ�Ԫ�أ������� [2,4,2] ���ǡ�
*/
class Solution {
public:
	long long maxAlternatingSum(vector<int>& nums) {
		typedef long long LL;
		int n = nums.size();
		const LL INF = 1e15;
		vector<vector<LL>> f(n + 1, vector<LL>(2, -INF));
		f[0][0] = 0;
		for (int i = 1; i <= n; i++)
		{
			f[i][0] = max(f[i - 1][0], f[i - 1][1] - nums[i - 1]);
			f[i][1] = max(f[i - 1][1], f[i - 1][0] + nums[i - 1]);
		}
		return max(f[n][0], f[n][1]);
	}
};
