#include<vector>
#include <string>

using namespace std;


/*
504. �߽�����
����һ������ num������ת��Ϊ 7 ���ƣ������ַ�����ʽ�����
*/
class Solution {
public:
	string convertToBase7(int num) {
		string res;
		bool isNeg = false;
		if (num < 0)
		{
			num *= -1;
			isNeg = true;
		}
		else if (!num)
		{
			res = '0';
		}
		while (num)
		{
			res += to_string(num % 7);
			num /= 7;
		}
		if (isNeg)
			res += '-';
		return string(res.rbegin(), res.rend());
	}
};