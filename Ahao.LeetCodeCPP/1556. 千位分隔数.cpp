#include<vector>
#include <string>

using namespace std;


/*
1556. ǧλ�ָ���
����һ������ n������ÿ����λ��ӵ㣨�� "." ���ţ���Ϊǧλ�ָ���������������ַ�����ʽ���ء�
*/
class Solution {
public:
	string thousandSeparator(int n) {
		string num = to_string(n);
		string res;
		for (int i = num.size() - 1, j = 0; i >= 0; i--, j++)
		{
			if (j % 3 == 0 && j)
				res += '.';
			res += num[i];
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
