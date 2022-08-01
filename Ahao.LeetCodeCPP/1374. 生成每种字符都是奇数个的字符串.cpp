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

class Solution {
public:
	string generateTheString(int n) {
		if (n % 2 == 1) {
			return string(n, 'a');
		}
		return string(n - 1, 'a') + 'b';
	}
};
