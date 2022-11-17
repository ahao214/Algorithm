#include<vector>
#include <algorithm>

using namespace std;


/*
1560. Բ�������Ͼ���������������
����һ������ n ��һ���������� rounds ����һ��Բ�������� n ��������ɣ�������Ŵ� 1 �� n ���ֽ������������Ͼٰ�һ�������ɱ�������������ȫ���� m ���׶���ɡ����У��� i ���׶ν�������� rounds[i - 1] ��ʼ�������� rounds[i] ������������˵���� 1 �׶δ� rounds[0] ��ʼ���� rounds[1] ������

������������ʽ���ؾ������������Ǽ������������������ ���� ���С�
*/
class Solution {
public:
	vector<int> mostVisited(int n, vector<int>& rounds) {
		vector<int> s(n + 1);
		for (int i = 0; i + 1 < rounds.size(); i++)
		{
			int a = rounds[i], b = rounds[i + 1];
			while (a != b)
			{
				s[a]++;
				a++;
				if (a > n) a -= n;
			}
		}
		s[rounds.back()]++;
		int c = 0;
		for (auto x : s) c = max(x, c);
		vector<int> res;
		for (int i = 1; i <= n; i++)
			if (s[i] == c)
				res.push_back(i);
		return res;
	}

	vector<int> mostVisited(int n, vector<int>& rounds) {
		vector<int> res;
		//a��ʾ��һ�� b��ʾ���һ��
		int a = rounds[0], b = rounds.back();
		if (b == a - 1 || (a == 1 && b == n))
		{
			for (int i = 1; i <= n; i++)
				res.push_back(i);
		}
		else {
			while (a != b)
			{
				res.push_back(a);
				if (++a > n) a -= n;
			}
			res.push_back(b);
			sort(res.begin(), res.end());
		}
		return res;
	}
};