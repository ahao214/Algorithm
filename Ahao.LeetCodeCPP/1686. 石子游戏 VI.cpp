#include<vector>

using namespace std;


/*
1686. ʯ����Ϸ VI
Alice �� Bob ������һ����Ϸ��Alice ���֡�

һ��ʯ�����ܹ��� n ��ʯ�ӣ��ֵ�ĳ�����ʱ�������� �Ƴ� һ��ʯ�Ӳ��õ����ʯ�ӵļ�ֵ��Alice �� Bob ��ʯ�Ӽ�ֵ�� ��һ���ĵ����б�׼ ��˫����֪���Է������б�׼��

������������Ϊ n ���������� aliceValues �� bobValues ��aliceValues[i] �� bobValues[i] �ֱ��ʾ Alice �� Bob ��Ϊ�� i ��ʯ�ӵļ�ֵ��

����ʯ�Ӷ���ȡ��󣬵÷ֽϸߵ���Ϊʤ�ߡ����������ҵ÷���ͬ����ôΪƽ�֡���λ��Ҷ������ ���Ų��� ������Ϸ��

�����ƶ���Ϸ�Ľ���������µķ�ʽ��ʾ��

��� Alice Ӯ������ 1 ��
��� Bob Ӯ������ -1 ��
�����Ϸƽ�֣����� 0 ��
*/
class Solution {
public:
	/*
	����a[i]+b[i]�Ӵ�С����
	*/
	int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
		vector<vector<int>> c;
		for (int i = 0; i < aliceValues.size(); i++)
		{
			c.push_back({ aliceValues[i] + bobValues[i],aliceValues[i],bobValues[i] });
		}
		sort(c.begin(), c.end());
		int res = 0;
		for (int i = aliceValues.size() - 1, j = 0; j < aliceValues.size(); i--, j++)
		{
			if (j % 2 == 0)
				res += c[i][1];
			else
				res -= c[i][2];
		}
		if (res > 0) return 1;
		if (!res) return 0;
		return -1;
	}
};
