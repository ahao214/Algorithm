#include<vector>

using namespace std;





/*
1906. ��ѯ�����ֵ����Сֵ
һ������ a �� �����ֵ����Сֵ ����Ϊ��0 <= i < j < a.length �� a[i] != a[j] �� |a[i] - a[j]| �� ��Сֵ����� a ������Ԫ�ض� ��ͬ ����ô�����ֵ����СֵΪ -1 ��

�ȷ�˵������ [5,2,3,7,2] �����ֵ����Сֵ�� |2 - 3| = 1 ��ע��𰸲�Ϊ 0 ����Ϊ a[i] �� a[j] ���벻��ȡ�
����һ���������� nums �Ͳ�ѯ���� queries ������ queries[i] = [li, ri] ������ÿ����ѯ i ������ ������ nums[li...ri] �� �����ֵ����Сֵ �������� nums[li...ri] ���� nums ���飨�±�� 0 ��ʼ�����±��� li �� ri ֮�������Ԫ�أ����� li �� ri ���ڣ���

���㷵�� ans ���飬���� ans[i] �ǵ� i ����ѯ�Ĵ𰸡�

������ ��һ��������������һ��Ԫ�ء�

|x| ��ֵ����Ϊ��

��� x >= 0 ����ôֵΪ x ��
��� x < 0 ����ôֵΪ -x ��
*/


const int N = 100010, M = 110;
int s[N][M];

class Solution {
public:
	vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size(), m = queries.size();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 100; j++)
			{
				int t = 0;
				if (nums[i - 1] == j) t = 1;
				s[i][j] = s[i - 1][j] + t;
			}
		}

		vector<int> res(m);
		for (int i = 0; i < m; i++)
		{
			int left = queries[i][0] + 1, right = queries[i][1] + 1;
			int t = M, last = -1;
			for (int j = 1; j <= 100; j++)
			{
				if (s[right][j] > s[left - 1][j])
				{
					if (last != -1) t = min(t, j - last);
					last = j;
				}
			}
			if (t == M) t = -1;
			res[i] = t;
		}
		return res;
	}
};
