#include<vector>
#include<string>

using namespace std;


/*
1447. ������
����һ������ n �����㷵������ 0 �� 1 ֮�䣨������ 0 �� 1�������ĸС�ڵ���  n �� ��� ���� ������������ ���� ˳�򷵻ء�
*/
class Solution {
public:
	//�����Լ��
	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}

	vector<string> simplifiedFractions(int n) {
		vector<string> res;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (gcd(i, j) == 1)
					res.push_back(to_string(j) + '/' + to_string(i));
			}
		}
		return res;
	}
};