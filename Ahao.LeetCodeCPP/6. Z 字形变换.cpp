using namespace std;
#include<string>
#include<vector>

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		vector<string> rows(numRows);
		//�������
		bool down = false;
		for (int i = 0, row = 0; i < s.length(); i++) {
			rows[row] += s[i];
			if (row == 0 || row == numRows - 1)
				down = !down;
			row += down ? 1 : -1;
		}
		string res = "";
		for (int i = 0; i < numRows; i++) {
			res += rows[i];
		}
		return res;
	}
};



/*
6. Z ���α任
��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "PAYPALISHIRING" ����Ϊ 3 ʱ���������£�

P   A   H   N
A P L S I I G
Y   I   R
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ�����
���磺"PAHNAPLSIIGYIR"��

����ʵ��������ַ�������ָ�������任�ĺ�����

string convert(string s, int numRows);
*/
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		string res;
		for (int i = 0; i < numRows; i++)
		{
			if (!i || i == numRows - 1)
			{
				for (int j = i; j < s.size(); j += 2 * (numRows - 1))
					res += s[j];
			}
			else
			{
				for (int j = i, k = 2 * (numRows - 1) - i; j < s.size() || k < s.size(); j += 2 * (numRows - 1), k += 2 * (numRows - 1))
				{
					if (j < s.size()) res += s[j];
					if (k < s.size()) res += s[k];
				}
			}
		}
		return res;
	}
};
