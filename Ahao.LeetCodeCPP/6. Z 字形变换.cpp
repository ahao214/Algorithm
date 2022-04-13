using namespace std;
#include<string>
#include<vector>

class Solution {
	/*
	6. Z ���α任
	��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�
	*/
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