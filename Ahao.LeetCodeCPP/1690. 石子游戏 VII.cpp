#include<vector>

using namespace std;


/*
1690. ʯ����Ϸ VII
ʯ����Ϸ�У�����˿�ͱ������������Լ��Ļغϣ�����˿�ȿ�ʼ ��

�� n ��ʯ���ų�һ�š�ÿ����ҵĻغ��У����Դ����� �Ƴ� ����ߵ�ʯͷ�����ұߵ�ʯͷ��������������ʣ��ʯͷֵ֮ �� ��ȵĵ÷֡���û��ʯͷ���Ƴ�ʱ���÷ֽϸ��߻�ʤ��

�������������������Ϸ�������ı������������䣩���������������� ��С�÷ֵĲ�ֵ ������˿��Ŀ��������޶ȵ� ����÷ֵĲ�ֵ ��

����һ���������� stones ������ stones[i] ��ʾ ����߿�ʼ �ĵ� i ��ʯͷ��ֵ���������˿�ͱ����� ���ӳ����ˮƽ ���뷵������ �÷ֵĲ�ֵ ��
*/
class Solution {
public:
	int stoneGameVII(vector<int>& stones) {
		int n = stones.size();
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++)
			s[i] = s[i - 1] + stones[i - 1];
		vector<vector<int>> f(n + 1, vector<int>(n + 1));
		for (int len = 2; len <= n; len++)
		{
			for (int i = 1; i + len - 1 <= n; i++)
			{
				int j = i + len - 1;
				f[i][j] = max(s[j] - s[i] - f[i + 1][j], s[j - 1] - s[i - 1] - f[i][j - 1]);
			}
		}
		return f[1][n];
	}
};