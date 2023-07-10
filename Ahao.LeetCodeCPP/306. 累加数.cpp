#include<vector>
#include <string>

using namespace std;


/*
306. �ۼ���

�ۼ��� ��һ���ַ���������������ֿ����γ��ۼ����С�

һ����Ч�� �ۼ����� ���� ���� ���� 3 �����������ʼ�����������⣬�����е�ÿ���������ֱ�������֮ǰ��������֮�͡�

����һ��ֻ�������� '0'-'9' ���ַ�������дһ���㷨���жϸ��������Ƿ��� �ۼ��� ������ǣ����� true �����򣬷��� false ��

˵�����ۼ������������������ 0 ֮�⣬���� �� 0 ��ͷ�����Բ������ 1, 2, 03 ���� 1, 02, 3 �������
*/
class Solution {
public:
	string add(string x, string y)
	{
		vector<int> A, B, C;
		for (int i = x.size() - 1; i >= 0; i--) A.push_back(x[i] - '0');
		for (int i = y.size() - 1; i >= 0; i--) B.push_back(y[i] - '0');
		for (int i = 0, t = 0; i < A.size() || i < B.size() || t; i++)
		{
			if (i < A.size()) t += A[i];
			if (i < B.size()) t += B[i];
			C.push_back(t % 10);
			t /= 10;
		}
		string z;
		for (int i = C.size() - 1; i >= 0; i--)
			z += to_string(C[i]);
		return z;
	}

	bool isAdditiveNumber(string num) {
		for (int i = 0; i < num.size(); i++)
		{
			for (int j = i + 1; j + 1 < num.size(); j++)
			{
				int a = -1, b = i, c = j;
				while (true)
				{
					if (b - a > 1 && num[a + 1] == '0' || c - b > 1 && num[b + 1] == '0') break;//��ǰ����

					auto x = num.substr(a + 1, b - a), y = num.substr(b + 1, c - b);
					auto z = add(x, y);
					if (num.substr(c + 1, z.size()) != z) break; //��һ������ƥ��
					a = b, b = c, c = c + z.size();
					if (c + 1 == num.size()) return true;
				}
			}
		}
		return false;
	}
};