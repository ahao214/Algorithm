#include<vector>
#include <string>

using namespace std;


/*
171. Excel �������

����һ���ַ��� columnTitle ����ʾ Excel ����е������ơ����� �������ƶ�Ӧ������� ��
*/


class Solution {
public:
	int titleToNumber(string columnTitle) {
		int res = 0;
		for (auto& c : columnTitle)
		{
			res = res * 26 - 'A' + c + 1;
		}
		return res;
	}
};