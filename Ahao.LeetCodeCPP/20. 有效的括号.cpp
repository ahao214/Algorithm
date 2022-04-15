using namespace std;
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>

class Solution {
public:
	bool isValid(string s) {
		unordered_map<char, char> pairs = {
			{'(',')'},{'[',']'},{'{','}'}
		};
		stack<char> stk;
		for (int i = 0; i < s.length(); i++) {
			if (pairs.find(s[i]) != pairs.end()) {
				stk.push(pairs[s[i]]);
			}
			else {
				if (stk.empty() || stk.top() != s[i]) {
					return false;
				}
				stk.pop();
			}
		}
		return stk.empty();
	}
};

