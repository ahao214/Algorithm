#include<string>

using namespace std;



/*
521. ��������� ��
*/
class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a == b) return -1;
		return max(a.size(), b.size());
	}
};