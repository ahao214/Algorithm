#include <string>
using namespace std;


class Solution {
	/*
	389. �Ҳ�ͬ
	���������ַ��� s �� t ������ֻ����Сд��ĸ��

	�ַ��� t ���ַ��� s ������ţ�Ȼ�������λ�����һ����ĸ��

	���ҳ��� t �б���ӵ���ĸ��
	*/
public:
	char findTheDifference(string s, string t) {
		char res = 0;
		for (auto c : s)
			res ^= c;
		for (auto c : t)
			res ^= c;
		return res;
	}
};