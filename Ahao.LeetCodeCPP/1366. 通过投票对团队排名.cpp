#include<vector>
#include <algorithm>
#include<string>

using namespace std;


/*
1366. ͨ��ͶƱ���Ŷ�����
������һ�����������ϵͳ�����ݲ����Ŷ���ͶƱ�����еĴ������������
ÿ��ͶƱ�߶���Ҫ���Ӹߵ��͵�˳��Բ��������������Ŷӽ�����λ��

�����������£�

�����Ŷӵ���������������������λ��һ����Ʊ�Ķ��پ�����
������ڶ���ŶӲ��е�����������������䡸��λ�ڶ�����Ʊ��������
�Դ����ƣ�ֱ�����ٴ��ڲ��е������
����ڿ���������ͶƱ�������Ȼ���ֲ�������
������Ŷ���ĸ����ĸ˳�����������
����һ���ַ������� votes ����ȫ��ͶƱ�߸�������λ�����
�����������������������в����Ŷӽ���������

���㷵���ܱ�ʾ������ϵͳ ����� �������Ŷ��������ַ�����
*/
class Solution {
public:
	string rankTeams(vector<string>& votes) {
		int n = votes[0].size();
		vector<vector<int>> ranks(26, vector<int>(n + 1));

		for (int i = 0; i < 26; i++)
			ranks[i][n] = -i;
		for (auto& vote : votes)
			for (int i = 0; i < n; i++)
				ranks[vote[i] - 'A'][i]++;

		sort(ranks.begin(), ranks.end(), greater<vector<int>>());

		string res;
		for (int i = 0; i < n; i++)
			res += -ranks[i][n] + 'A';
		return res;
	}
};