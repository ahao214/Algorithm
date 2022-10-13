#include<vector>

using namespace std;



/*
1744. ����������ϲ��������Ե�����ϲ�����ǹ���
����һ���±�� 0 ��ʼ������������ candiesCount ������ candiesCount[i] ��ʾ��ӵ�еĵ� i ���ǹ�����Ŀ��ͬʱ����һ����ά���� queries ������ queries[i] = [favoriteTypei, favoriteDayi, dailyCapi] ��

�㰴�����¹������һ����Ϸ��

��ӵ� 0 �쿪ʼ���ǹ���
���ڳ��� ���� �� i - 1 ���ǹ�֮ǰ������ ���κ�һ�ŵ� i ���ǹ���
�ڳ��������ǹ�֮ǰ�������ÿ�� ���� �� һ�� �ǹ���
���㹹��һ������������ answer �����Ը��� queries ��ÿһ��Ķ�Ӧ�𰸡����������㣺

answer.length == queries.length ��answer[i] �� queries[i] �Ĵ𰸡�
answer[i] Ϊ true �������ǣ���ÿ��� ������ dailyCapi ���ǹ���ǰ���£�������ڵ� favoriteDayi ��Ե��� favoriteTypei ���ǹ������� answer[i] Ϊ false ��
ע�⣬ֻҪ�������� 3 �������еĵڶ���������Ϳ�����ͬһ��Բ�ͬ���͵��ǹ���

���㷵�صõ������� answer ��
*/
class Solution {
public:
	typedef long long LL;
	bool check(LL a, LL b, LL c, LL d)
	{
		if (b < c || d < a)
			return false;
		return true;
	}

	vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
		int n = candiesCount.size();
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + candiesCount[i - 1];

		vector<bool> res;
		for (auto& q : queries)
		{
			//t��ʾ�ǹ������� d��ʾ�ڼ��� c��ʾÿ�����Ե��ǹ�������
			int t = q[0], d = q[1], c = q[2];
			res.push_back(check(d + 1, (LL)(d + 1) * c, s[t] + 1, s[t + 1]));
		}

		return res;
	}
};