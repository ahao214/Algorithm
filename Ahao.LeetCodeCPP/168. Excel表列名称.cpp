#include<vector>
#include <string>

using namespace std;


/*
168. Excel��������

����һ������ columnNumber ���������� Excel �������Ӧ�������ơ�
*/

class Solution {
public:
	string convertToTitle(int columnNumber) {
		string res;
		while (columnNumber)
		{
			int remainder = columnNumber % 26;
			if (remainder == 0)
			{
				remainder = 26;
				columnNumber -= 26;
			}
			res += remainder + 'A' - 1;
			columnNumber /= 26;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
