#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	string generateTheString(int n) {
		string res;
		if (n % 2 == 0) res += 'b', n--;
		while (n--) res += 'a';
		return res;
	}
};