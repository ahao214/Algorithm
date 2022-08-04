#include<vector>
#include<string>

using namespace std;


/*
2055. ����֮�������
����һ�������ӣ����������Ӻ������ų�һ�С�����һ���±�� 0 ��ʼ���ַ��� s ����ֻ�����ַ� '*' �� '|' ������ '*' ��ʾһ�� ���� ��'|' ��ʾһ֧ ���� ��

ͬʱ����һ���±�� 0 ��ʼ�Ķ�ά�������� queries ������ queries[i] = [lefti, righti] ��ʾ ���ַ��� s[lefti...righti] ���������Ҷ˵���ַ���������ÿ����ѯ������Ҫ�ҵ� ���ַ����� �� ��֧����֮�� �����ӵ� ��Ŀ �����һ�������� ���ַ����� ��ߺ��ұ� �� ������һ֧������ô������������� ��֧����֮�� ��

�ȷ�˵��s = "||**||**|*" ����ѯ [3, 8] ����ʾ�������ַ��� "*||**|" �����ַ���������֧����֮���������ĿΪ 2 �����ַ������ұ�����������������ߺ��ұ� �� ������һ֧����
���㷵��һ���������� answer ������ answer[i] �ǵ� i ����ѯ�Ĵ𰸡�
*/
class Solution {
public:
	vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
		int n = s.size();
		vector<int> str(n + 1), left(n + 1), right(n + 2, n + 1);
		for (int i = 1; i <= n; i++)
		{
			str[i] = str[i - 1];
			if (s[i - 1] == '*') str[i]++, left[i] = left[i - 1];
			else left[i] = i;
		}
		for (int i = n; i; i--)
			if (s[i - 1] == '*') right[i] = right[i + 1];
			else right[i] = i;

		vector<int> res;
		for (auto& q : queries)
		{
			int a = right[q[0] + 1], b = left[q[1] + 1];
			if (a > b) res.push_back(0);
			else res.push_back(str[b] - str[a - 1]);
		}
		return res;
	}
};