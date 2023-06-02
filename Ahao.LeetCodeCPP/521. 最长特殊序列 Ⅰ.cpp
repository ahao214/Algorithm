#include<string>

using namespace std;



/*
521. 最长特殊序列 Ⅰ
*/
class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a == b) return -1;
		return max(a.size(), b.size());
	}
};